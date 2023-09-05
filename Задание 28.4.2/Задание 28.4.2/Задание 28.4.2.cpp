staticbool done2 = false;
queue<Part::PartPtr> shared_queue2;
mutex lock_queue2;
condition_variable event_holder2;


void threadCwork(Part::PartPtr& part) {
    part->volume -= 0.5;
    this_thread::sleep_for(chrono::milliseconds(500 + rand() % 6000));

    locked_output("threadCwork finished with part " + to_string(part->part_id));
}


void threadB() {
    srand(1000000);
    while (true) {
        list<Part::PartPtr> parts_for_work;
        {
            unique_lock<mutex> m_holder(lock_queue);

            if (done && shared_queue.empty()) {
                break;
            }

            if (shared_queue.empty()) {
                event_holder.wait(m_holder, []() { return !shared_queue.empty() || done; });
            }
            for (size_t i = 0; i < shared_queue.size(); i++)
            {
                parts_for_work.push_back(shared_queue.front());
                shared_queue.pop();
            }
            locked_output("Parts were removed from queue");
        }
        for (auto& p : parts_for_work)
        {
            threadBwork(p);
            lock_guard<mutex> raii_obj(lock_queue2);
            shared_queue2.push(p);
            event_holder2.notify_one();
        }
    }
    done2 = true;
    event_holder2.notify_one();
}


void threadC() {
    srand(5555555);
    while (true) {
        list<Part::PartPtr> parts_for_work;
        {
            unique_lock<mutex> m_holder(lock_queue2);

            if (done2 && shared_queue2.empty()) break;

            if (shared_queue2.empty()) {
                event_holder2.wait(m_holder, []() { return !shared_queue2.empty() || done2; });
            }
            for (size_t i = 0; i < shared_queue2.size(); i++)
            {
                parts_for_work.push_back(shared_queue2.front());
                shared_queue2.pop();
            }
        }
        for (auto& p : parts_for_work)
            threadCwork(p);
    }
}


int main(int argc, char* argv[])
{

    list<Part::PartPtr> spare_parts;
    for (int i = 0; i < 5; i++) {
        spare_parts.push_back(Part::PartPtr(new Part{ i + 1, 10.0 }));
    }

    thread ta(threadA, ref(spare_parts));
    thread tb(threadB);
    thread tc(threadC);

    ta.join();
    tb.join();
    tc.join();

    locked_output("done");
    return 0;
}
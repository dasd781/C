/*
Перепишите запуск потоков из задания 28.4.2 с помощью связки async и future. 
Синхронизируйте окончание выполнения потоков с помощью полученных фьючерсов, избавившись от переменных done.
*/

voidthreadA(list<Part::PartPtr>& input) {
    srand(77777777);
    size_t size = input.size();
    for (size_t i = 0; i < size; i++) {
        // обрабатываем деталь
        threadAwork(*input.begin());
        // кладем в очередь
        {
            lock_guard<mutex> raii_obj(lock_queue);
            shared_queue.push(Part::PartPtr(*input.begin()));
            input.remove(*input.begin());
            locked_output("Part was added to queue");
            event_holder.notify_one();
        }
    }
}

void threadB(future<void>& a_res) {
    srand(1000000);
    while (true) {
        list<Part::PartPtr> parts_for_work;
        {
            unique_lock<mutex> m_holder(lock_queue);

            if (a_res.wait_for(chrono::seconds(0)) == future_status::ready
                && shared_queue.empty()) {
                break;
            }

            if (shared_queue.empty()) {
                event_holder.wait(m_holder, [&a_res]() {
                    return !shared_queue.empty() ||
                        a_res.wait_for(chrono::seconds(0)) == future_status::ready;
                    });
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
    event_holder2.notify_one();
}

void threadC(future<void>& b_res) {
    srand(5555555);
    while (true) {
        list<Part::PartPtr> parts_for_work;
        {
            unique_lock<mutex> m_holder(lock_queue2);

            if (b_res.wait_for(chrono::seconds(0)) == future_status::ready
                && shared_queue2.empty()) break;

            if (shared_queue2.empty()) {
                event_holder2.wait(m_holder, [&b_res]() {
                    return !shared_queue2.empty() ||
                        b_res.wait_for(chrono::seconds(0)) == future_status::ready;
                    });
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

    future<void> a_res = async(launch::async, threadA, std::ref(spare_parts));
    future<void> b_res = async(launch::async, threadB, std::ref(a_res));
    future<void> c_res = async(launch::async, threadC, std::ref(b_res));

    a_res.wait();
    event_holder.notify_one();
    b_res.wait();
    event_holder2.notify_one();
    c_res.wait();

    cout << "done";
    return 0;
}
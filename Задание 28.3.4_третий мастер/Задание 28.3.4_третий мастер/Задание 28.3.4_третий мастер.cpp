
#include "queue"
#include "list"
#include <mutex>
#include <thread>
#include <random>
#include <memory>
#include <string>
#include <iostream>

using namespace std;


// структура детали
typedef struct Part {
    int part_id;
    float volume;
    typedef shared_ptr<struct Part> PartPtr; // умный указатель
} Part;



static bool done2 = false;
static bool done = false;
queue<Part::PartPtr> shared_queue;
mutex lock_queue;
mutex lock_cout;
queue<Part::PartPtr> shared_queue2;
mutex lock_queue2;

void threadCwork(Part::PartPtr& part) {
    part->volume -= 0.5;
    this_thread::sleep_for(chrono::milliseconds(500 + rand() % 6000));
}


void threadB() {
    srand(100000);
    while (true) {
        Part::PartPtr part_for_work;
        {
            lock_queue.lock();
            if (shared_queue.empty()) {
                lock_queue.unlock();
                if (done) break;
                locked_output("threadB useless check, queue is empty. Going to bed");
                this_thread::sleep_for(chrono::milliseconds(1000));
                continue;
            }
            else {
                part_for_work = shared_queue.front();
                shared_queue.pop();
                lock_queue.unlock();
                locked_output("Part was removed from queue");
            }
        }
        thread Bwork(part_for_work);
        lock_guard<mutex> raii_obj(lock_queue2);
        shared_queue2.push(part_for_work);
    }
    done2 = true;
}


void threadC() {
    srand(5555555);
    while (true) {
        Part::PartPtr part_for_work;
        {
            lock_queue2.lock();
            if (shared_queue2.empty()) {
                lock_queue2.unlock();
                if (done2) break;
                locked_output("threadC useless check, queue is empty. Going to bed");
                this_thread::sleep_for(chrono::milliseconds(1000));
                continue;
            }
            else {
                part_for_work = shared_queue2.front();
                shared_queue2.pop();
                lock_queue2.unlock();
            }
        }
        threadCwork(part_for_work);
    }
}



int main(int argc, char* argv[])
{
    list<Part::PartPtr> spare_parts;
    for (int i = 1; i <= 5; i++) {
        spare_parts.push_back(Part::PartPtr(new Part{ i, 10.0 }));
    }

    thread ta(threadA, ref(spare_parts));
    thread tb(threadB);
    thread tc(threadC);

    ta.join();
    tb.join();
    tc.join();

    cout << "done" << endl;
}
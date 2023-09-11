




using namespace std;

struct thread_interrupt_struct {
    thread_interrupt_struct() :
        thread_interrupt_flag(false),
        cv(nullptr) {
    }
    mutex m_defender;
    bool thread_interrupt_flag;
    condition_variable* cv;
};

thread_local thread_interrupt_struct tis;

void InterruptableThread::interrupt() {
    lock_guard<mutex> lg(m_defender);
    if (m_pFlag)
        lock_guard<mutex> lg(m_pFlag->m_defender);
    m_pFlag->thread_interrupt_flag = true;
    if (m_pFlag->cv) {
        m_pFlag->cv->notify_one();
        m_pFlag->cv = nullptr;
    }
}

void InterruptableThread::interruptableWait(
    std::condition_variable& cv,
    std::unique_lock<std::mutex>& ul,
    std::function<bool()> predicate) {
        {
            lock_guard<mutex> lg(tis.m_defender);
            tis.cv = &cv;
        }
        try {
            cv.wait(ul, [&] {return predicate() || checkInterrupted(); });
        }
        catch (...) {

        }
        lock_guard<mutex> lg(tis.m_defender);
        tis.cv = nullptr;
}

bool InterruptableThread::checkInterrupted() {
    return tis.thread_interrupt_flag;
}

void pop(T& item) {
    unique_lock<mutex> l(m_locker);
    if (m_task_queue.empty())
        InterruptableThread::interruptableWait(m_event_holder, l, [this] {return !m_task_queue.empty(); });
    if (m_task_queue.empty()) return;
    item = move(m_task_queue.front());
    m_task_queue.pop();
}

void OptimizedThreadPool::threadFunc(int qindex) {
    while (true) {
        if (InterruptableThread::checkInterrupted()) {
            cout << "thread was interrupted" << endl;
            return;
        }
        task_type task_to_do;
        bool res;
        int i = 0;
        for (; i < m_thread_count; i++) {
            if (res = m_thread_queues[(qindex + i) % m_thread_count].fast_pop(task_to_do))
                break;
        }
        if (!res) {
            m_thread_queues[qindex].pop(task_to_do);
        }
        else if (!task_to_do.valid()) {
            m_thread_queues[(qindex + i) % m_thread_count].push(task_to_do);
        }

        if (InterruptableThread::checkInterrupted()) {
            cout << "thread was interrupted" << endl;
            return;
        }

        if (!task_to_do.valid()) {
            return;
        }
        task_to_do();
    }
}
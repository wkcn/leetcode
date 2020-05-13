// TODO: 信号量
class H2O {
public:
    H2O() : num_h(0) {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mt);
        cv.wait(lck, [this]{return num_h < 2;});
        releaseHydrogen();
        ++num_h;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mt);
        cv.wait(lck, [this]{return num_h == 2;});
        num_h = 0;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        cv.notify_all();
    }
private:
    int num_h;
    mutex mt;
    condition_variable cv;
};

class H2O {
public:
    H2O() {
        num_h = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        while (num_h > 1) std::this_thread::yield();
        ++num_h;
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        while (num_h < 2) std::this_thread::yield();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        num_h -= 2;
    }
private:
    atomic<int> num_h;
};

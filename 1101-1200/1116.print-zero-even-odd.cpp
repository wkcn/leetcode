class ZeroEvenOdd {
private:
    int n;
    mutex mt;
    condition_variable cv;
    int i;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        i = 0;
        // 0102030405
        // 0123456789
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mt);
        for (int s = 0; s < 2 * n; s += 2) {
            cv.wait(lck, [this]{return i % 2 == 0;});
            printNumber(0);
            ++i;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mt);
        for (int s = 3; s < 2 * n; s += 4) {
            cv.wait(lck, [this]{return i % 4 == 3;});
            printNumber((i+1)/2);
            ++i;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mt);
        for (int s = 1; s < 2 * n; s += 4) {
            cv.wait(lck, [this]{return i % 4 == 1;});
            printNumber((i+1)/2);
            ++i;
            cv.notify_all();
        }
    }
};

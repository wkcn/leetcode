// TODO: atomic
class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lck(mt);
        for (int s = 3; s <= n; s += 3) {
            if (s % 15 == 0) continue;
            cv.wait(lck, [this]{return i % 3 == 0 && i % 5 != 0;});
            printFizz();
            ++i;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lck(mt);
        for (int s = 5; s <= n; s += 5) {
            if (s % 15 == 0) continue;
            cv.wait(lck, [this]{return i % 5 == 0 && i % 3 != 0;});
            printBuzz();
            ++i;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lck(mt);
        for (int s = 15; s <= n; s += 15) {
            cv.wait(lck, [this]{return i % 15 == 0;});
            printFizzBuzz();
            ++i;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mt);
        for (int s = 1; s <= n; ++s) {
            if (s % 3 == 0 || s % 5 == 0) continue;
            cv.wait(lck, [this]{return i % 3 != 0 && i % 5 != 0;});
            printNumber(i);
            ++i;
            cv.notify_all();
        }
    }
private:
    mutex mt;
    condition_variable cv;
    int i;
};

// wait, notify_all会释放锁
class FooBar {
private:
    int n;
    mutex mt;
    condition_variable cv1, cv2;
    int state;

public:
    FooBar(int n) {
        this->n = n;
        state = 0;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mt);
            // printFoo() outputs "foo". Do not change or remove this line.
            cv1.wait(lck, [&](){return state == 0;});
            printFoo();
            state = 1;
            cv2.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mt);
        	// printBar() outputs "bar". Do not change or remove this line.
            cv2.wait(lck, [&](){return state == 1;});
        	printBar();
            state = 0;
            cv1.notify_all();
        }
    }
};

class FooBar {
private:
    int n;
    mutex mt;
    condition_variable cv;
    int state;

public:
    FooBar(int n) {
        this->n = n;
        state = 0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lck(mt);
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            if (i > 0) cv.wait(lck, [&](){return state == 0;});
        	printFoo();
            state = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lck(mt);
        for (int i = 0; i < n; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
            cv.wait(lck, [&](){return state == 1;});
        	printBar();
            state = 0;
            cv.notify_all();
        }
    }
};

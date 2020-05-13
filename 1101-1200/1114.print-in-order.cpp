// TODO: 还可以用semaphore
//
class Foo {
public:
    Foo() {
        lck2.lock();
        lck3.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lck2.unlock();
    }

    void second(function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        lck2.lock();
        printSecond();
        lck3.unlock();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        lck3.lock();
        printThird();
    }
private:
    std::mutex lck2, lck3;
};

class Foo {
public:
    Foo() : state(1) {

    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {

        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lck(mt);
        cv.wait(lck, [&](){return state == 2;});
        printSecond();
        state = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lck(mt);
        cv.wait(lck, [&](){return state == 3;});
        printThird();
    }
private:
    mutex mt;
    condition_variable cv;
    int state;
};

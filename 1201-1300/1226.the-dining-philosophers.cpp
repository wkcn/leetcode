class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left = philosopher;
        int right = (philosopher + 1) % 5;
        bool use_left = false, use_right = false;
        if (forks[left].try_lock()) {
            pickLeftFork();
            use_left = true;
        }
        if (forks[right].try_lock()) {
            pickRightFork();
            use_right = true;
        }
        if (use_left && use_right) {
            eat();
        }
        if (use_left) {
            putLeftFork();
            forks[left].unlock();
        }
        if (use_right) {
            putRightFork();
            forks[right].unlock();
        }
    }
private:
    array<mutex, 5> forks;
};

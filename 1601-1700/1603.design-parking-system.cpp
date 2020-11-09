class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        nums[1] = big;
        nums[2] = medium;
        nums[3] = small;
    }
    
    bool addCar(int carType) {
        if (nums[carType] > 0) {
            --nums[carType];
            return true;
        }
        return false;
    }
private:
    array<int, 4> nums;
};

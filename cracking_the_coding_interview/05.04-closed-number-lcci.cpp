// ones可以在向前推动时数
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        //     0b110011001100
        //略大：0b110011010001
        //略小：0b110011001010

        // 略大，找从后往前第一个01左移，后面的1全部合并右移动远离
        // 略小，找从后往前第一个10右移, 后面的1全部合并左移动靠近
        unsigned int b = 1, nextb = 0b10;
        int larger = -1, smaller = -1;
        for (int i = 0; i < 30; ++i, b = nextb, nextb <<= 1) {
            if ((num & b) && ((num & nextb) == 0)) {
                // xxxx01110
                //     nb
                int mask = nextb - 1;
                int ones = get1s(num & mask); // n后面的1的个数
                larger = ((num | nextb) & (~mask)) | ((1 << (ones-1)) - 1);
                break;
            }
        }
        b = 1; nextb = 0b10;
        for (int i = 0; i < 30; ++i, b = nextb, nextb <<= 1) {
            if ((num & b) == 0 && (num & nextb)) {
                // xxxx10111
                //     nb
                int mask = nextb - 1;
                int ones = get1s(num & mask);
                int deln = i - ones;
                smaller = ((num & (~nextb)) | mask) & (~((1<<deln)-1));
                break;
            }
        }
        return {larger, smaller};
    }
    int get1s(int num) {
        int cnt = 0;
        while (num) {
            num &= num - 1;
            ++cnt;
        }
        return cnt;
    }
};

#if SOLUTION == 1
class Solution {
public:
    int maximum(int a, int b) {
        int64_t diff = (int64_t)a - (int64_t)b;
        bool sign = bool(diff & (1L << 63));
        return sign * b + (1 - sign) * a;
    }
};
#elif SOLUTION == 2
class Solution {
public:
    int maximum(int a, int b) {
        bool sign = ((int64_t)a - (int64_t)b) >> 63;
        return sign * b + (!sign) * a;
    }
};
#elif SOLUTION == 3
// reference: 
// https://leetcode-cn.com/problems/maximum-lcci/solution/ji-yu-wei-yun-suan-shi-xian-da-xiao-bi-jiao-by-dex/
// uint8_t abs: (var ^ (var >> 7)) - (var >> 7)
// ABS
class Solution {
public:
    int maximum(int a, int b) {
      int64_t su = (uint64_t)a + (uint64_t)b;
      int64_t diff = (uint64_t)a - (uint64_t)b;
      // abs
      diff = (diff ^ (diff >> 63)) - (diff >> 63);
      return (su + diff) / 2; // 因为被除数可能是负数，不能用移位
    }
};
#endif

#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        deque<float> q;
        for (int x : nums) q.push_back(x);
        return go(q);
    }
    bool go(deque<float> &q) {
        const int len = q.size();
        if (len == 1) {
            return abs(q.front() - 24) < eps;
        }
        for (int i = 0; i < len; ++i) {
            // 注意a, b的类型是float
            float a = q.front(); q.pop_front();
            for (int j = 1; j < len; ++j) {
                float b = q.front(); q.pop_front();
                if (gen(q, a + b) ||
                    gen(q, a - b) ||
                    gen(q, a * b) ||
                    (b && gen(q, a / b))) { // 要避免除以0
                    // 让函数结束时, q的大小和输入时一致
                    q.push_back(b);
                    q.push_back(a);
                    return true;
                }
                q.push_back(b);
            }
            q.push_back(a);
        }
        return false;
    }
    inline bool gen(deque<float> &q, float v) {
        q.push_back(v);
        bool b = go(q);
        q.pop_back();
        return b;
    }
private:
    const float eps = 1e-5;
};


#elif SOLUTION == 2

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        list<float> q;
        for (int x : nums) q.push_back(x);
        return go(q);
    }
    bool go(list<float> &q) {
        const int len = q.size();
        if (len == 1) {
            return abs(q.front() - 24) < eps;
        }
        for (int i = 0; i < len; ++i) {
            // 注意a, b的类型是float
            float a = q.front(); q.pop_front();
            for (int j = 1; j < len; ++j) {
                float b = q.front(); q.pop_front();
                if (gen(q, a + b) ||
                    gen(q, a - b) ||
                    gen(q, a * b) ||
                    (b && gen(q, a / b))) { // 要避免除以0
                    // 让函数结束时, q的大小和输入时一致
                    q.push_back(b);
                    q.push_back(a);
                    return true;
                }
                q.push_back(b);
            }
            q.push_back(a);
        }
        return false;
    }
    inline bool gen(list<float> &q, float v) {
        q.push_back(v);
        bool b = go(q);
        q.pop_back();
        return b;
    }
private:
    const float eps = 1e-5;
};

#endif

int main() {
  vector<int> nums;
  INPUT_ARRAY(nums);
  cout << Solution().judgePoint24(nums) << endl;
  return 0;
}

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int su = 0;;
        int best_len = INT32_MAX;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // [left, i]
            su += nums[i];
            while (su >= s && i >= left) {
                best_len = min(best_len, i - left + 1);
                su -= nums[left++];
            }
        }
        return best_len == INT32_MAX ? 0 : best_len;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int su = 0;
        int best_len = INT32_MAX;
        vector<int> presum(nums.size() + 1);
        presum[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            presum[i+1] = presum[i] + nums[i];
        }
        // input: 2, 3, 1, 2, 4, 3
        // presum: 0, 2, 5, 6, 8, 12, 15
        for (int i = 0; i < nums.size(); ++i) {
            auto p = lower_bound(presum.begin() + i + 1, presum.end(), s + presum[i]);
            if (p != presum.end()) {
                best_len = min(best_len, int(p - (presum.begin() + i)));
            }
        }
        return best_len == INT32_MAX ? 0 : best_len;
    }
};

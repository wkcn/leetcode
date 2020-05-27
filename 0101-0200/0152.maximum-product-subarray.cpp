class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos = 1, neg = 1;
        int ans = nums[0];
        for (int &x : nums) {
            if (x == 0) {
                pos = 0; neg = 0;
            } else if (x > 0) {
                pos = max(x, pos * x);
                neg = neg * x;
            } else {
                int old_pos = pos;
                pos = neg * x;
                neg = min(x, x * old_pos);
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        const int size = nums.size();
        vector<int> min_arr(size), max_arr(size);
        min_arr[0] = max_arr[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            int x = nums[i];
            int a = min_arr[i-1] * x;
            int b = max_arr[i-1] * x;
            min_arr[i] = min({x, a, b});
            max_arr[i] = max({x, a, b});
            ans = max(max_arr[i], ans);
        }
        return ans;
    }
};

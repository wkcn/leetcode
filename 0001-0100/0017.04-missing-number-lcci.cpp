class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int i = 0;
        int j = 1; // 下一个可以和n替换的地方
        while (i < n) {
            if (nums[i] == n) {
                j = max(i + 1, j);
                while (j < n && nums[j] == j) ++j;
                if (j < n) swap(nums[i], nums[j]);
                else return i;
            } else {
                if (nums[i] != i) {
                    swap(nums[i], nums[nums[i]]);
                } else ++i;
            }
        }
        return n;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s ^= i;
            s ^= nums[i];
        }
        return s ^ n;
    }
};

// 还可以用求和的方式

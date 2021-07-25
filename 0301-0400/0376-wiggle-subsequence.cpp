class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        // 假如上升序列遇到更大的值，下次下降时，肯定是最近的值为波峰
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                up = max(up, down + 1);
            } else if (nums[i - 1] > nums[i]) {
                down = max(down, up + 1);
            }
        }
        return max(up, down);
    }
};

// 统计波峰波谷
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cnt = 1;
        int diff = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] < nums[i]) {
                if (diff < 0) {
                    ++cnt;
                }
            } else if (nums[i-1] > nums[i]) {
                if (diff > 0) {
                    ++cnt;
                }
            }
            int new_diff = nums[i] - nums[i-1];
            if (new_diff != 0) diff = new_diff;
        }
        if (diff != 0) ++cnt;
        return cnt;
    }
};

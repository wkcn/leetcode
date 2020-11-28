class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) ans.push_back(i + 1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int x : nums) {
            int i = abs(x) - 1;
            if (nums[i] > 0) nums[i] *= -1;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};

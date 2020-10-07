class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int size = nums.size();
        vector<vector<int> > out;
        for (int i = 0; i < size - 3; ++i) {
            if (nums[i] * 4 > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < size - 2; ++j) {
                if (nums[i] + nums[j] * 3 > target) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = size - 1;
                int rest = target - nums[i] - nums[j];
                while (left < right) {
                    int su = nums[left] + nums[right];
                    if (su == rest) {
                        out.push_back({nums[i], nums[j], nums[left], nums[right]});
                        --right;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    } else if (su > rest) {
                        --right;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    } else {
                        ++left;
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                    }
                }
            }
        }
        return out;
    }
};

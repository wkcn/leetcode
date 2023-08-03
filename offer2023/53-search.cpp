class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt = 0;
        for (int x : nums) if (x == target) ++cnt;
        return cnt;
    }
};

int my_lower_bound(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        nums[mid] < target ? lo = mid + 1 : hi = mid;
    }
    return lo;
}

int my_upper_bound(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        nums[mid] <= target ? lo = mid + 1 : hi = mid;
    }
    return lo;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return my_upper_bound(nums, target) - \
            my_lower_bound(nums, target);
    }
};

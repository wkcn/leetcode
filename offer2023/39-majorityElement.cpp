class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v = 0;
        int cnt = 0;
        for (int e : nums) {
            if (cnt == 0) {
                v = e; cnt = 1;
            } else if (v == e) ++cnt;
            else {
                --cnt;
            }
        }
        return v;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return me(nums, 0, nums.size()).first;
    }
    pair<int, int> me(vector<int>& nums, int start, int end) {
        // return: {majorityelem, cnt}
        if (end - start == 1) return {nums[start], 1};
        int mid = start + ((end - start) >> 1);
        auto lm = me(nums, start, mid);
        auto rm = me(nums, mid, end);
        if (lm.first == rm.first) return {lm.first, lm.second + rm.second};
        for (int i = start; i < mid; ++i) {
            if (nums[i] == rm.first) ++rm.second;
        }
        for (int i = mid; i < end; ++i) {
            if (nums[i] == lm.first) ++lm.second;
        }
        return lm.second >= rm.second ? lm : rm;
    }
};

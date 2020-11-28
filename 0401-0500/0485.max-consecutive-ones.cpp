class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int n = nums.size();
        int i = 0, j = 0;
        int best = 0;
        while (i < n) {
            while (i < n && nums[i] != 1) ++i;
            j = i;
            while (j < n && nums[j] == 1) ++j;
            best = max(best, j - i);
            i = j + 1;
        }
        return best;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int n = nums.size();
        int cnt = 0;
        int best = 0;
        for (int x : nums) {
            if (x == 0) cnt = 0;
            else {
                best = max(best, ++cnt);
            }
        }
        return best;
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int ans = 0;
        for (int i = 1; i < timeSeries.size(); ++i) {
            ans += min(duration, timeSeries[i] - timeSeries[i-1]);
        }
        ans += duration;
        return ans;
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int last_end = -1;  // [0, last_end) 中毒
        int ans = 0;
        for (int x : timeSeries) {
            // [x, x + duration - 1] = [x, x + duration)
            ans += max(duration - max(0, last_end - x), 0);
            last_end = x + duration;
        }
        return ans;
    }
};

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int t = 0;
        int max_time = -1;
        char c = 0;
        for (int i = 0; i < releaseTimes.size(); ++i) {
            int u = releaseTimes[i] - t;
            if (u > max_time || (u == max_time && keysPressed[i] > c)) {
                max_time = u;
                c = keysPressed[i];
            }
            t = releaseTimes[i];
        }
        return c;
    }
};

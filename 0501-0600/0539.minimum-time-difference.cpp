class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (string &s : timePoints) {
            times.push_back(tom(s));
        }
        sort(times.begin(), times.end());
        int ans = times[0] + 24 * 60 - times.back();
        for (int i = 1; i < times.size(); ++i) {
            ans = min(ans, times[i] - times[i - 1]);
        }
        return ans;
    }
    int tom(string &s) {
        const int h = (s[0] - '0') * 10 + (s[1] - '0');
        const int m = (s[3] - '0') * 10 + (s[4] - '0');
        return h * 60 + m;
    }
};

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        array<int, 24 * 60> vis{0};
        int mi = 24 * 60 + 1, ma = -1;
        for (string &s : timePoints) {
            int m = tom(s);
            if (vis[m]) return 0;
            vis[m] = true;
            mi = min(mi, m);
            ma = max(ma, m);
        }
        int ans = mi + 24 * 60 - ma;
        for (int i = mi + 1; i < 24 * 60; ++i) {
            if (vis[i]) {
                ans = min(ans, i - mi);
                mi = i;
            }
        }
        return ans;
    }
    int tom(string &s) {
        const int h = (s[0] - '0') * 10 + (s[1] - '0');
        const int m = (s[3] - '0') * 10 + (s[4] - '0');
        return h * 60 + m;
    }
};

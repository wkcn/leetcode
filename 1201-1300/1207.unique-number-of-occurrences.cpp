class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // [-1000, 1000] -> [0, 2000]
        int cnts[2001] = {0};
        for (int x : arr) ++cnts[x + 1000];
        sort(cnts, cnts + 2001);
        for (int i = 0; i < 2000; ++i) {
            if (cnts[i] != 0 && cnts[i] == cnts[i + 1]) return false;
        }
        return true;
    }
};

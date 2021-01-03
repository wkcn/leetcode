class Solution {
public:
    int minCount(vector<int>& coins) {
        int t = 0;
        for (int x : coins) {
            t += (x + 1) / 2;
        }
        return t;
    }
};

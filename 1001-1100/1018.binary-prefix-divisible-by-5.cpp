class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        // (a * 2 + b) % 5 == 0
        int v = 0;
        vector<bool> ans;
        for (int x : A) {
            v = (v * 2 + x) % 5;
            ans.push_back(v == 0);
        }
        return ans;
    }
};

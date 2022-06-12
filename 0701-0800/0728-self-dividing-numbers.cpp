class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i)
            if (is_sd(i)) ans.push_back(i);
        return ans;
    }
    bool is_sd(int v) {
        int r = v;
        while (r > 0) {
            int e = r % 10;
            if (e == 0) return false;
            if (v % e) return false;
            r /= 10;
        }
        return true;
    }
};

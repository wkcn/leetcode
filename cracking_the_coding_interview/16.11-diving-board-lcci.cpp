class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        // 注意k == 0时的情况
        if (k == 0) return {};
        vector<int> res;
        int L = shorter * k;
        res.push_back(L);
        int diff = longer - shorter;
        // 假如longer和shorter一样长！！
        if (diff != 0)
            for (int i = 0; i < k; ++i) {
                L += diff;
                res.push_back(L);
            }
        return res;
    }
};

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // 映射回原本的顺序坐标
        int t = label >> 1;
        int i = 0;
        while (t != 0) {
            t >>= 1;
            ++i;
        }
        // 根节点i == 0
        // i为偶数是顺序，奇数是逆序
        vector<int> ans;
        // [1 << i, (1 << (i+1))-1]
        // (1 << i) + (1 << i) * 2 - 1 = (1 << i) * 3 - 1
        int r = i & 1 ? ((1 << i) * 3 - 1 - label) : label;
        for (int y = i; y >= 0; --y) {
            int v = y & 1 ? ((1 << y) * 3 - 1) - r : r;
            ans.push_back(v);
            r /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

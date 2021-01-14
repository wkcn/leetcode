class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        // isConnected[i][j] = sum(isConnected[i][k] * isConnected[k][j])
        while (1) {
            bool changed = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isConnected[i][j]) continue;
                    for (int k = 0; k < n; ++k) {
                        if (isConnected[i][k] && isConnected[k][j]) {
                            changed = true;
                            isConnected[i][j] = true;
                            break;
                        }
                    }
                }
            }
            if (!changed) break;
        }
        int ans = 0;
        vector<bool> used(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                ++ans;
                used[i] = true;
                for (int k = 0; k < n; ++k) {
                    if (isConnected[i][k]) used[k] = true;
                }
            }
        }
        return ans;
    }
};

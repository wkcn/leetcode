// bitset得整体用效率才高
constexpr int M = 100 * 200;
bool vis[M + 1];

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        memset(vis, 0, sizeof(vis));
        int su = 0, ma = 0;
        for (int i = 0; i < nums.size(); ++i) {
            su += nums[i];
            ma = max(ma, nums[i]);
        }
        if (su % 2 == 1) return false;
        if (ma * 2 > su) return false;

        vis[0] = 1;
        int target = su / 2;
        for (int v : nums) {
            for (int u = M; u >= v; --u) {
                vis[u] = vis[u] || vis[u - v];
            }
        }
        return vis[su / 2];
    }
};

constexpr int M = 100 * 200 + 1;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int su = accumulate(nums.begin(), nums.end(), 0);
        if (su & 1) return false;
        bitset<M> vis(1);
        for (int v : nums) vis |= vis << v;
        return vis[su >> 1];
    }
};

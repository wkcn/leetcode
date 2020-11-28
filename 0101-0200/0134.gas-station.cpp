class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int i = 0;
        while (i < n) {
            // 从i出发
            int g = gas[i];
            int j = 0;
            while (j < n && g > 0) {
                int u = (i + j) % n;
                g -= cost[u];
                if (g < 0) break;
                ++j;
                if (g == 0) break;
                g += gas[(i + j) % n];
            }
            if (j >= n) return i;
            i = i + j + 1;
        }
        return -1;
    }
};

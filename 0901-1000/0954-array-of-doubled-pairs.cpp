// TODO: 试下拓扑排序？
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> cnts;
        for (int x : arr) ++cnts[x];
        for (int x : arr) {
            if (cnts[x]) {
                --cnts[x];
                if (x < 0 && x % 2 == -1) return false;
                int y = x >= 0 ? x * 2 : x / 2;
                if (--cnts[y] < 0) return false;
            }
        }
        return true;
    }
};

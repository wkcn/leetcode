// 滑动窗口
class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        int left = 0, right = 0; // [left, right)
        unordered_set<int> small_set(small.begin(), small.end());
        unordered_map<int, int> big_map;
        int best = INT32_MAX;
        int left_v;
        while (right < big.size()) {
            while (right < big.size()) {
                const int v = big[right++];
                if (small_set.count(v)) {
                    ++big_map[v];
                    if (big_map.size() == small_set.size()) break;
                }
            }
            if (small_set.size() != big_map.size()) break;
            while (left < right) {
                const int v = big[left++];
                if (small_set.count(v)) {
                    auto p = big_map.find(v);
                    if (--(p->second) == 0) {
                        big_map.erase(p);
                        break;
                    }
                }
            }
            const int len = right - left + 1;
            if (len < best) {
                best = len;
                left_v = left - 1;
            }
        }
        if (best == INT32_MAX) return {};
        return {left_v, left_v + best - 1};
    }
};

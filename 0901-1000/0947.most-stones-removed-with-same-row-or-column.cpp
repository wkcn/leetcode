// 连通分量 + 并查集
class UnionFind {
public:
    void connect(int a, int b) {
        int pa = find_parents(a);
        int pb = find_parents(b);
        if (pa != pb) --cnt_;
        ma_[pa] = pb;
    }
    int get_cnt() const {
        return cnt_;
    }
private:
    int find_parents(int x) {
        auto p = ma_.insert({x, x});
        if (p.second) {
            ++cnt_;
        }
        if (p.first->second == x) {
            return x;
        }
        return p.first->second = find_parents(p.first->second);
    }
    unordered_map<int, int> ma_;
    int cnt_ = 0;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for (auto &v : stones) {
            // 注意坐标0
            uf.connect(-v[0] - 1, v[1]);
        }
        return stones.size() - uf.get_cnt();
    }
};

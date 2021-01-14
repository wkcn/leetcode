// 并查集找连通域 + 桶排序
class Counter {
public:
    Counter() {
        fill(cnts.begin(), cnts.end(), 0);
        i = 0;
    }
    void push(char c) {
        ++cnts[c - 'a'];
    }
    char get() {
        while (cnts[i] == 0) ++i;
        --cnts[i];
        return i + 'a';
    }
private:
    array<int, 26> cnts;
    int i;
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // 连通域内排序
        // 不能用图，因为O(n^2)会超时
        const int n = s.size();
        vector<int> parents(n);
        for (int i = 0; i < n; ++i) parents[i] = i;
        for (vector<int> &p : pairs) {
            int pa = get_parent(parents, p[0]);
            int pb = get_parent(parents, p[1]);
            parents[pa] = pb;
        }
        vector<int> ids(n);
        vector<Counter> cnts(n);
        for (int i = 0; i < n; ++i) {
            int p = get_parent(parents, i);
            cnts[p].push(s[i]);
        }
        string ans(n, ' ');
        for (int i = 0; i < n; ++i) {
            ans[i] = cnts[get_parent(parents, i)].get();
        }
        return ans;
    }
private:
    int get_parent(vector<int> &p, int i) {
        if (p[i] == i) return i;
        return p[i] = get_parent(p, p[i]);
    }
};

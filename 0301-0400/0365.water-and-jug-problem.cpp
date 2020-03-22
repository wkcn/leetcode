// [GOOD][TODO] 有数学的解法！
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        set<pair<int, int> > se;
        stack<pair<int, int> > st;
        se.insert({0, 0});
        st.push({0, 0});
        while (!st.empty()) {
            auto p = st.top(); st.pop();
            if (p.first + p.second == z) return true;
            Push({x, p.second}, se, st);
            Push({p.first, y}, se, st);
            Push({0, p.second}, se, st);
            Push({p.first, 0}, se, st);
            if (p.first > 0 && p.second < y) {
                int rest = y - p.second;
                if (p.first >= rest) {
                    Push({p.first - rest, y}, se, st);
                } else {
                    Push({0, p.first+p.second}, se, st);
                }
            }
            if (p.second > 0 && p.first < x) {
                int rest = x - p.first;
                if (p.second >= rest) {
                    Push({x, p.second - rest}, se, st);
                } else {
                    Push({p.first+p.second, 0}, se, st);
                }
            }
        }
        return false;
    }
    void Push(pair<int, int> p, set<pair<int,int> > &se, stack<pair<int,int> > &st) {
        if (!se.count(p)) {
            se.insert(p); st.push(p);
        }
    }
};

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bitset<256> vis{false};
        for (char c : J) vis[c] = true;
        int cnt = 0;
        for (char c : S) {
            if (vis[c]) ++cnt;
        }
        return cnt;
    }
};

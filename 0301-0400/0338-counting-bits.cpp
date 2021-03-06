class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> buf;
        buf.push_back(0);
        for (int i = 1; i <= num; ++i) {
            buf.push_back(buf[i >> 1] + (i & 1));
        }
        return buf;
    }
};

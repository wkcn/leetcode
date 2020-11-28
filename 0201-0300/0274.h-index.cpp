class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int i;
        for (i = 0; i < citations.size(); ++i) {
            if (citations[i] < (i + 1)) break;
        }
        return i;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int len = citations.size();
        if (len == 0) return 0;
        vector<int> cnts(len + 1, 0);
        for (int x : citations) {
            ++cnts[min(x, len)];
        }
        int cnt = 0;
        for (int h = len; h >= 0; --h) {
            cnt += cnts[h];
            if (cnt >= h) return h;
        }
        return 0;
    }
};

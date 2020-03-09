class Solution {
public:
    int findString(vector<string>& words, string s) {
        int lo = 0, hi = words.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int old_mid = mid; // 注意这里!!!
            while (words[mid].empty() && mid >= lo) --mid;
            if (mid < lo) lo = old_mid + 1;
            else {
                if (words[mid] == s) return mid;
                words[mid] < s ? lo = old_mid + 1 : hi = mid;
            }
        }
        return -1;
    }
};

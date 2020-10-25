class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i = 0;
        int best = 0;
        while (i < A.size()) {
            int j = i;
            while (j + 1 < A.size() && A[j] < A[j + 1]) ++j;
            if (i < j) {
                // j 此时是山顶
                int k = j;
                while (k + 1 < A.size() && A[k] > A[k + 1]) ++k;
                if (j < k) {
                    // k 是有效的山脚
                    best = max(best, k - i + 1);
                    i = k;
                } else {
                    i = k + 1;
                }
            } else {
                i = j + 1;
            }
        }
        return best;
    }
};

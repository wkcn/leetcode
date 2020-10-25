class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.empty()) return {};
        int p = lower_bound(A.begin(), A.end(), 0) - A.begin();
        for_each(A.begin(), A.end(), [](int &x) {x *= x;});
        int left = p - 1;
        int right = p;
        vector<int> res(A.size());
        int i = 0;
        while (i < A.size()) {
            if (left < 0) {
                res[i++] = A[right++];
            } else if (right >= A.size()) {
                res[i++] = A[left--];
            } else if (A[left] < A[right]) {
                res[i++] = A[left--];
            } else {
                res[i++] = A[right++];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.empty()) return {};
        vector<int> out(A.size());
        int k = (int)A.size() - 1;
        for (int i = 0, j = (int)A.size() - 1; i <= j;) {
            if (abs(A[i]) < abs(A[j])) {
                out[k--] = A[j] * A[j];
                --j;
            } else {
                out[k--] = A[i] * A[i];
                ++i;
            }
        }
        return out;
    }
};

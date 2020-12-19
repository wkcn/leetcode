class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        // 假设最长的边已经固定, 肯定是选最接近它的两条边
        const int n = A.size();
        if (n < 3) return 0;
        sort(A.rbegin(), A.rend());
        for (int i = 2; i < n; ++i) {
            if (A[i] + A[i - 1] > A[i - 2]) return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
    }
};

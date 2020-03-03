class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        hanota(A, B, C, A.size());
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C, int n) {
        if (n == 0) return;
        hanota(A, C, B, n-1);
        C.push_back(A.back()); A.pop_back();
        hanota(B, A, C, n-1);
    }
};

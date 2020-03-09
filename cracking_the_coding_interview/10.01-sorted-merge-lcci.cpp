class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int cur = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0){
            if(A[i] > B[j]){
                A[cur] = A[i];
                i--;
                cur--;
            }
            else{
                A[cur] = B[j];
                j--;
                cur--;
            }
        }
        while(i >= 0){
            A[cur] = A[i];
            cur--;
            i--;
        }
        while(j >= 0){
            A[cur] = B[j];
            cur--;
            j--;
        }
    
    }
};

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        const int n = arr.size();
        for (int i = n - 1; i > 0; --i) {
            auto p = max_element(arr.begin(), arr.begin() + i + 1);
            if (p != arr.end() - 1) {
                ans.push_back(p - arr.begin() + 1);
                reverse(arr.begin(), p + 1);
                ans.push_back(i + 1);
                reverse(arr.begin(), arr.begin() + i + 1);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int len = A.size();
        vector<int> res;
        for (int i = len - 1; i >= 1; --i) {
            if (A[i] == i + 1) continue;
            auto p = max_element(A.begin(), A.begin() + i + 1);
            if (p != A.begin()) {
                res.push_back(p - A.begin() + 1);
                reverse(A.begin(), p + 1);
            }
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + i + 1);
        }
        return res;
    }
};

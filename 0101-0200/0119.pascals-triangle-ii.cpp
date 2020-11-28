class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // C(k, i) = k! / (i ! * (k - i)!)
        // k! / (0! * k!), k! / (1! * (k-1)!)

        vector<int> ans;
        unsigned long long s = 1;
        ans.push_back(1);
        for (int i = 1; i <= rowIndex; ++i) {
            s = s * (rowIndex - i + 1) / i;
            ans.push_back((int)s);
        }
        return ans;
    }
};

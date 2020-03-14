class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> rec;
        for (int &v : nums) {
            // 可以先比较v与rec.back()
            auto p = lower_bound(rec.begin(), rec.end(), v);
            if (p == rec.end()) rec.push_back(v);
            else *p = v;
        }
        return rec.size();
    }
};

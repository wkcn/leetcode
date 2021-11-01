class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ma;
        stack<int> st;  // min stack
        for (int i = 0; i < nums2.size(); ++i) {
            ma[nums2[i]] = i;
        }
        for (int i = (int)nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() && nums2[i] >= st.top()) st.pop();
            if (st.empty()) {
                st.push(nums2[i]);
                nums2[i] = -1;   
            }
            else {
                int t = st.top(); st.push(nums2[i]); nums2[i] = t;
            }   
        }
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = nums2[ma[nums1[i]]];
        }
        return ans;
    }
};

// TODO: 理解
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int len = heights.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i <= len; ++i) {
            int h = i < len ? heights[i] : 0;
            while (st.top() != -1 && h < heights[st.top()]) {
                int r = heights[st.top()]; st.pop();
                int w = i - st.top() - 1;
                ans = max(ans, w * r);
            }
            st.push(i);
        }
        return ans;
    }
};

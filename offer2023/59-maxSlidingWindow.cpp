class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int> > q;
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            q.push({nums[i], i});
        }
        ans.push_back(q.top().first);
        for (int i = k; i < nums.size(); ++i) {
            q.push({nums[i], i});
            while (i - q.top().second >= k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// 下标递增，数字递减
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;  // 单调队列，左边是最大值且坐标在左边
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (i - q.front() >= k) q.pop_front();
            if (i >= k - 1)
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

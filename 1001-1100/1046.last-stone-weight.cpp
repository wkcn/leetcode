class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() >= 2) {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            int v = a - b;
            if (v > 0) q.push(v);
        }
        return q.empty() ? 0 : q.top();
    }
};

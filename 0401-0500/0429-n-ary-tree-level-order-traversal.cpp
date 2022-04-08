class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q; q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            int s = q.size();
            vector<int> buf;
            while (s-- > 0) {
                auto r = q.front(); q.pop();
                buf.push_back(r->val);
                for (auto t : r->children) q.push(t);
            }
            ans.emplace_back(move(buf));
        }
        return ans;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node*> q; q.push(root);
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int s = q.size();
            while (s-- > 0) {
                Node *r = q.front(); q.pop();
                for (auto t : r->children) q.push(t);
            }
        }
        return ans;
    }
};

// 注意nullptr作为输入
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        map<Node*, Node*> ma;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node *r = q.front(); q.pop();
            ma[r] = new Node(r->val);
            for (Node *u : r->neighbors) {
                if (!ma.count(u))
                    q.push(u);
            }
        }
        q.push(node);
        set<Node*> vis;
        vis.insert(node);
        while (!q.empty()) {
            Node *r = q.front(); q.pop();
            Node *t = ma[r];
            for (Node *u : r->neighbors) {
                t->neighbors.push_back(ma[u]);
                if (!vis.count(u)) {
                    vis.insert(u);
                    q.push(u);
                }
            }
        }
        return ma[node];
    }
};

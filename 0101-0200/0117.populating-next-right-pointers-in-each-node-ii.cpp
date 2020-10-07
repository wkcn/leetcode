/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *r = root;
        while (r) {
            Node *p = r;
            Node *last = nullptr;
            while (p) {
                if (p->left) {
                    if (last) last->next = p->left;
                    last = p->left;
                }
                if (p->right) {
                    if (last) last->next = p->right;
                    last = p->right;
                }
                p = p->next;
            }
            // 找到下一层非空的节点
            p = r;
            r = nullptr;
            while (p) {
                if (p->left) {
                    r = p->left;
                    break;
                }
                if (p->right) {
                    r = p->right;
                    break;
                }
                p = p->next;
            }
        }
        return root;
    }
};

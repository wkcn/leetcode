// TODO: 题解方法2
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
        Node *h = root;
        while (h) {
            Node *r = h;
            Node *last = nullptr;
            Node *next_first = nullptr;
            while (r) {
                if (r->left) {
                    if (!next_first) next_first = r->left;
                    if (last) last->next = r->left;
                    last = r->left;
                }
                if (r->right) {
                    if (!next_first) next_first = r->right;
                    if (last) last->next = r->right;
                    last = r->right;
                }
                r = r->next;
            }
            h = next_first;
        }
        return root;
    }
};

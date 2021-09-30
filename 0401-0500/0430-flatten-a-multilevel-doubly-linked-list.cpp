class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        return go(head).first;
    }
    pair<Node*, Node*> go(Node *p) {
        Node *start = p;
        Node *end = p;
        while (p) {
            if (p->child) {
                auto [left, right] = go(p->child);
                Node *next = p->next;

                p->next = left;
                left->prev = p;

                right->next = next;
                // next may be null
                if (next)
                    next->prev = right;

                p->child = nullptr;
                end = right;
                p = right->next;
            } else {
                end = p;
                p = p->next;
            }
        }
        return {start, end};
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        flatten_return_last(head);
        return head;
    }
    Node *flatten_return_last(Node *p) {
        while (p) {
            if (p->child) {
                Node *next = p->next;

                p->next = p->child;
                p->child->prev = p;

                Node *t = flatten_return_last(p->child);
                p->child = nullptr;

                t->next = next;
                if (next) next->prev = t;
                p = t;
            }
            if (!p->next) return p;
            p = p->next;
        }
        return nullptr;
    }
};

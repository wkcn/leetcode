/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        auto p = head;
        while (p) {
            auto r = new Node(p->val);
            r->next = p->next;
            p->next = r;
            p = r->next;
        }
        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        auto ans = head->next;
        p = head;
        while (p->next->next) {
            auto r = p->next;
            auto n1 = r->next;
            auto n2 = n1->next;
            p->next = n1;
            r->next = n2;
            p = n1;
        }
        p->next->next = nullptr;
        p->next = nullptr;
        return ans;
    }
};

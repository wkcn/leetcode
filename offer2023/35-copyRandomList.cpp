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
        if (!head) return {};
        unordered_map<Node*, int> ma;
        auto get_id = [&](Node *r) -> int {
            return ma[r];
        };
        Node *p = head;
        vector<Node*> vs;
        while (p) {
            ma[p] = ma.size();
            vs.push_back(new Node(p->val));
            p = p->next;
        }
        
        p = head;
        while (p) {
            int i = get_id(p);
            if (p->next)
                vs[i]->next = vs[get_id(p->next)];
            if (p->random)
                vs[i]->random = vs[get_id(p->random)];
            p = p->next;
        }
        return vs[0];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return {};
        Node dummy(0); dummy.next = head;
        Node *p = &dummy;

        // dummy -> old1 -> new1
        while (p->next) {
            Node *r = p->next;
            Node *e = new Node(r->val);
            e->next = r->next;
            r->next = e;
            p = e;
        }

        p = &dummy;
        while (p->next) {
            Node *r = p->next;
            Node *c = r->next;
            if (r->random)
                c->random = r->random->next;
            p = c;
        }

        p = &dummy;
        Node *res = p->next->next;
        // dummy(p) -> old1(r) -> new1(c)
        while (p->next) {
            Node *r = p->next;
            Node *c = r->next;
            r->next = c->next;
            if (c->next)
                c->next = c->next->next;
            p = r;
        }
        return res;
    }
};

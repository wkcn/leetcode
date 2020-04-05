// TODO: 用std::list写
struct MyNode {
    int key;
    int value;
    MyNode *left, *right;
    MyNode(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {

    }
};

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity), head(-1, -1), tail(-1, -1) {
        head.right = &tail;
        tail.left = &head;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            MyNode *node = cache[key];
            update(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (cache.count(key)) {
            MyNode *node = cache[key];
            update(node);
            cache[key]->value = value;
        } else {
            if (cache.size() >= cap) {
                // remove head.right
                MyNode *r = head.right;
                head.right = r->right;
                r->right->left = &head;
                cache.erase(r->key);
                delete r;
            }
            MyNode *u = new MyNode(key, value);
            tail.left->right = u;
            u->left = tail.left;
            u->right = &tail;
            tail.left = u;
            cache[key] = u;
        }
    }
private:
    void update(MyNode *node) {
        node->left->right = node->right;
        node->right->left = node->left;
        tail.left->right = node;
        node->left = tail.left;
        node->right = &tail;
        tail.left = node;
    }
private:
    int cap;
    unordered_map<int, MyNode*> cache;
    MyNode head, tail;
};

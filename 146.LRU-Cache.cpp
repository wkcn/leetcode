#include "common.h"

struct Node {
  Node *left, *right;
  int val;
  int key;
  Node() : key(-1) {
  }
};

class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {
      nodes_.resize(capacity + 2);
      head_ = &nodes_[0];
      tail_ = &nodes_[capacity + 1];
      head_->right = &nodes_[1];
      tail_->left = &nodes_[capacity];
      for (int i = 1; i <= capacity; ++i) {
        nodes_[i].left = &nodes_[i-1];
        nodes_[i].right = &nodes_[i+1];
      }  
    }
    
    int get(int key) {
      if (cache_.count(key)) {
        Node* r = cache_[key];
        _move_to_tail(r);
        return r->val;
      }
      return -1;
    }
    
    void put(int key, int value) {
      if (cache_.count(key)) {
        Node* r = cache_[key];
        r->val = value;
        _move_to_tail(r);
      } else {
        Node* r = head_->right;
        if (r->key > 0) {
          cache_.erase(r->key);
        }
        r->val = value;
        r->key = key;
        cache_[key] = r;
        _move_to_tail(r);
      }
    }
private:
    void _move_to_tail(Node* r) {
      // unlink
      r->left->right = r->right;
      r->right->left = r->left;

      r->left = tail_->left;
      r->right = tail_;

      tail_->left->right = r;
      tail_->left = r;
    }
private:
  map<int, Node*> cache_;
  Node *head_, *tail_;
  vector<Node> nodes_;
  int capacity_;
};

int main() {
  LRUCache cache = LRUCache( 2 /* capacity */ );

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;       // returns 1
  cache.put(3, 3);    // evicts key 2
  cout << cache.get(2) << endl;       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cout << cache.get(1) << endl;       // returns -1 (not found)
  cout << cache.get(3) << endl;       // returns 3
  cout << cache.get(4) << endl;       // returns 4
  return 0;
}

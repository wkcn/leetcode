#include "common.h"

#if 0
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
      root = new Node();
    }
    ~Trie() {
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        Node* r = q.front(); q.pop();
        for (int i = 0; i < 26; ++i) {
          if (r->nodes[i]) q.push(r->nodes[i]);
        }
        delete r;
      }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      Node* r = root;
      for (char c : word) {
        int ic = c - 'a';
        if (!r->nodes[ic]) r->nodes[ic] = new Node();
        r = r->nodes[ic];
      }
      r->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      Node* r = prefix_node(word);
      return r && r->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      Node* r = prefix_node(prefix);
      return r;
    }
private:
    struct Node {
      Node* nodes[26];
      bool is_word;
      Node() : is_word(false) {
        memset(nodes, 0, sizeof(nodes));
      }
    };
private:
    Node* prefix_node(const string &prefix) {
      Node* r = root;
      for (const char &c : prefix) {
        int ic = c - 'a';
        if (!r->nodes[ic]) return nullptr;
        r = r->nodes[ic];
      }
      return r;
    }
private:
    Node* root;
};
#else

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
      root = new Node();
    }
    ~Trie() {
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        Node* r = q.front(); q.pop();
        if (r->next) q.push(r->next);
        if (r->children) q.push(r->children);
        delete r;
      }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      Node* r = root;
      for (const char& c : word) {
        if (!r->children) {
          r->children = new Node(c); 
          r = r->children;
        } else {
          r = r->children;
          r = find_or_create(r, c);
        }
      }
      r->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      Node* r = prefix_node(word);
      return r && r->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      Node* r = prefix_node(prefix);
      return r;
    }
private:
    struct Node {
      Node* next;
      Node* children;
      char c;
      bool is_word;
      Node() : next(nullptr), children(nullptr), is_word(false) {
      }
      Node(char c_) : next(nullptr), children(nullptr), c(c_), is_word(false) {
      }
    };
private:
    Node* find_or_create(Node* r, char c) {
      if (r->c == c) return r;
      while (r->next) {
        r = r->next;
        if (r->c == c) return r;
      }
      r->next = new Node(c);
      return r->next;
    }
    Node* prefix_node(const string& prefix) {
      Node* r = root;
      for (const char& c : prefix) {
        if (!r->children) return nullptr;
        else {
          r = r->children;
          while (r->c != c) {
            r = r->next;
            if (!r) return nullptr;
          }
        } 
      }
      return r;
    }
private:
    Node* root;
};


#endif

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie trie;

  trie.insert("apple");
  cout << trie.search("apple") << endl;   // returns true
  cout << trie.search("app") << endl;     // returns false
  cout << trie.startsWith("app") << endl; // returns true
  trie.insert("app");   
  cout << trie.search("app") << endl;     // returns true
  return 0;
}

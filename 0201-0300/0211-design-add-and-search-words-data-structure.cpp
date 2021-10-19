class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
    
    void addWord(string word) {
        Node *p = &root;
        for (char c : word) {
            Node* &r = p->nodes[c - 'a'];
            if (!r) {
                r = new Node();
            }
            p = r;
        }
        p->is_leaf = true;
    }
    
    bool search(string word) {
        if (word.empty()) return true;
        stack<pair<int, Node*> > st; st.emplace(0, &root);
        while (!st.empty()) {
            auto [i, p] = st.top(); st.pop();
            if (i >= word.size()) {
                if (p->is_leaf) return true;
                continue;
            }
            char c = word[i];
            if (c == '.') {
                for (int e = 0; e < 26; ++e) {
                    auto r = p->nodes[e];
                    if (r) st.emplace(i + 1, r);
                }
            } else {
                auto r = p->nodes[c - 'a'];
                if (r) st.emplace(i + 1, r);
            }
        }
        return false;
    }
private:
    struct Node {
        Node *nodes[26];
        bool is_leaf;
        Node() {
            memset(nodes, 0, sizeof(nodes));
            is_leaf = false;
        }
        ~Node() {
            for (Node *r : nodes) {
                delete r;
            }
        }
    };
    Node root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

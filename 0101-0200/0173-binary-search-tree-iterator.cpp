/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        // LVR
        cur = root;
    }
    
    int next() {
        // cur != nullptr
        while (1) {
            if (cur->left) {
                TreeNode *p = cur->left;
                while (p->right && p->right != cur) p = p->right;
                if (p->right == cur) {
                    p->right = nullptr;
                    int v = cur->val;
                    cur = cur->right;
                    return v;
                } else {
                    p->right = cur;
                    cur = cur->left;
                }
            } else {
                int v = cur->val;
                cur = cur->right;
                return v;
            }
        }
        return -1;
    }
    
    bool hasNext() {
        return cur != nullptr;
    }
private:
    TreeNode *cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }

    int next() {
        // cur != nullptr
        while (cur->left) {
            TreeNode *p = cur->left;
            while (p->right && p->right != cur) p = p->right;
            if (p->right) {
                p->right = nullptr;
                break;
            } else {
                p->right = cur;
                cur = cur->left;
            }
        }
        int v = cur->val;
        cur = cur->right;
        return v;
    }

    bool hasNext() {
        return cur != nullptr;
    }
private:
    TreeNode *cur;
};


class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        PushLeft(root);
    }

    int next() {
        TreeNode *r = st.top();
        st.pop();
        PushLeft(r->right);
        return r->val;
    }

    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;
    void PushLeft(TreeNode *root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};


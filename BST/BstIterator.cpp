// LC 173: Binary Search Tree Iterator (Medium)
// Approach: Controlled inorder traversal using a stack.
//           Stores only the current search path to keep space within O(H).
// Time: next() is amortized O(1) time (each node is pushed and popped exactly once).
//       hasNext() is O(1) time.
// Space: O(H) auxiliary space to store path nodes where H is the height of the tree.

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

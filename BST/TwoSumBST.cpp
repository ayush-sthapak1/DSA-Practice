// LC 653: Two Sum IV - Input is a BST (Medium)
// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Approach: Bidirectional BSTIterator (Two Pointer technique).
//           One iterator goes forward (ascending), one goes backward (descending).
// Time: O(N) where N is the number of nodes in the BST (each node is visited at most once).
// Space: O(H) auxiliary space to store the path stacks where H is the height of the tree.

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = (reverse) ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll((reverse) ? temp->left : temp->right);
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;

        BSTIterator l(root, false); // Ascending iterator
        BSTIterator r(root, true);  // Descending iterator

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }
        return false;
    }
};

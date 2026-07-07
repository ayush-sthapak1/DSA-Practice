// LC 101: Symmetric Tree (Easy)
// Link: https://leetcode.com/problems/symmetric-tree/
// Approach: Recursive Mirror DFS.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.

class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {
        // Base cases
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        // Value check
        if (p->val != q->val) return false;

        // Symmetric (mirror) recursive check
        return helper(p->left, q->right) && helper(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return helper(root->left, root->right);
    }
};

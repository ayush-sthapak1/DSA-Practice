 // LC 110: Balanced Binary Tree (Easy)
// Approach: Optimal Post-Order DFS (Single-Pass Height & Balance Check)
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (recursion stack depth)

class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Recurse Left
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is unbalanced

        // Recurse Right
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is unbalanced

        // Check if the current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

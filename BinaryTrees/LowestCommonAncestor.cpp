// LC 236: Lowest Common Ancestor of a Binary Tree (Medium)
// Approach: Single-pass recursive DFS.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If we reach a null node, or find either target node, return it.
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Recurse left and right
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both subtrees return non-null, this node is the LCA split point
        if (left && right) {
            return root;
        }

        // Otherwise, return whichever subtree returned a non-null node
        return left ? left : right;
    }
};

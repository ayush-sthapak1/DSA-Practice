// LC 104: Maximum Depth of Binary Tree (Easy)
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Approach: Recursive Depth-First Search (DFS) / Post-Order Aggregation
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (recursion stack depth)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: An empty tree has height/depth of 0
        if (root == nullptr) {
            return 0;
        }

        // Post-Order DFS: Collect depths of subtrees and add 1 for the current node
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// LC 124: Binary Tree Maximum Path Sum (Hard)
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Approach: Optimal Post-Order DFS (Single-Pass Height-style Path Aggregation with Negative Pruning)
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (recursion stack depth)

class Solution {
public:
    int calculateBranchSum(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }

        // Recurse: Collect max path sums of left and right subtrees.
        // Neglect negative paths by taking max(0, ...)
        int leftBranch = max(0, calculateBranchSum(root->left, maxSum));
        int rightBranch = max(0, calculateBranchSum(root->right, maxSum));

        // Update the global maximum path sum (path turning at the current node)
        maxSum = max(maxSum, root->val + leftBranch + rightBranch);

        // Return the single longest branch sum including the current node's value
        return root->val + max(leftBranch, rightBranch);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculateBranchSum(root, maxSum);
        return maxSum;
    }
};

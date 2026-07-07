// LC 1373: Maximum Sum BST in Binary Tree (Hard)
// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Approach: Bottom-up recursive postorder DFS.
//           Each node collects isBST, min, max, and sum from its children.
//           Updates a class member 'maxSum' only when a valid BST is identified.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.

class NodeVals {
public:
    bool isBST;
    int minNode, maxNode, sum;
    NodeVals(bool isBST, int minNode, int maxNode, int sum) {
        this->isBST = isBST;
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxSum;

    NodeVals helper(TreeNode* root) {
        if (root == nullptr) {
            return NodeVals(true, INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if current tree is a valid BST
        if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
            int currentSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currentSum);

            return NodeVals(true, min(root->val, left.minNode), max(root->val, right.maxNode), currentSum);
        }

        // If not a BST, return invalid limits
        return NodeVals(false, INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        helper(root);
        return maxSum;
    }
};

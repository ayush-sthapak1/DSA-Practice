// LC 222: Count Complete Tree Nodes (Easy)
// Link: https://leetcode.com/problems/count-complete-tree-nodes/
// Approach: Height comparison of left and right spines.
//           If leftmost height == rightmost height, the tree is perfect, return (1 << height) - 1.
//           Otherwise, recursively count nodes: 1 + countNodes(left) + countNodes(right).
// Time: O((log N)^2) since we do O(log N) height calculations at each of the O(log N) step divisions.
// Space: O(log N) auxiliary space for recursion stack.

class Solution {
private:
    int LeftHeight(TreeNode* root) {
        int height = 0;
        while (root != nullptr) {
            height++;
            root = root->left;
        }
        return height;
    }

    int RightHeight(TreeNode* root) {
        int height = 0;
        while (root != nullptr) {
            height++;
            root = root->right;
        }
        return height;
    }

public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = LeftHeight(root);
        int rightHeight = RightHeight(root);

        // If the leftmost and rightmost heights match, it's a perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        // Otherwise, recursively count nodes in subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

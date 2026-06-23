// LC 543: Diameter of Binary Tree (Easy)
// Approach: Optimal Post-Order DFS (Single-Pass Height & Diameter Calculation)
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (recursion stack depth)

class Solution {
public:
    int calculateHeight(TreeNode* root, int& maxDiameter) {
        if (root == nullptr) {
            return 0;
        }

        // Recurse: Get heights of left and right subtrees
        int leftHeight = calculateHeight(root->left, maxDiameter);
        int rightHeight = calculateHeight(root->right, maxDiameter);

        // Update global maximum diameter (path passing through current node)
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return height of current node to its parent
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateHeight(root, maxDiameter);
        return maxDiameter;
    }
};

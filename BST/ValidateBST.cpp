// LC 98: Validate Binary Search Tree (Medium)
// Approach: Recursive DFS range validation (minVal, maxVal).
//           Allows early termination as soon as a range violation is encountered.
// Time: O(N) where N is the number of nodes in the BST.
// Space: O(H) auxiliary space for recursion stack where H is the height of the tree.

class Solution {
private:
    bool helper(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;
        if (root->val >= maxVal || root->val <= minVal) return false;
        
        return helper(root->left, minVal, root->val) && 
               helper(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};

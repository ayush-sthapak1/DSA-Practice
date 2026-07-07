// LC 700: Search in a Binary Search Tree (Easy)
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Approach: Iterative search using BST property.
// Time: O(H) where H is the height of the tree (O(log N) for balanced trees, O(N) for skewed trees).
// Space: O(1) auxiliary space.

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        
        while (root != nullptr && root->val != val) {
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};

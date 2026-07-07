// LC 1008: Construct Binary Search Tree from Preorder Traversal (Medium)
// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Approach: Recursive single-pass traversal using an upper bound constraint.
// Time: O(N) where N is the number of nodes (each element is checked once).
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.

class Solution {
private:
    TreeNode* helper(vector<int>& preorder, int& idx, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = helper(preorder, idx, root->val);
        root->right = helper(preorder, idx, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return helper(preorder, idx, INT_MAX);
    }
};

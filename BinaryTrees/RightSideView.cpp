// LC 199: Binary Tree Right Side View (Medium)
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Approach: Right-to-Left Pre-order DFS (Root -> Right -> Left).
//           We only add the first node we encounter at each depth (when result.size() == row).
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.



class Solution {
private:
    void helper(TreeNode* root, vector<int>& result, int row) {
        if (root == nullptr) return;

        // If this is the first node we see at this depth, it is the rightmost node
        if (result.size() == row) {
            result.push_back(root->val);
        }

        // Traverse right first so that the rightmost node of each row is visited first
        helper(root->right, result, row + 1);
        helper(root->left, result, row + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, result, 0);
        return result;
    }
};

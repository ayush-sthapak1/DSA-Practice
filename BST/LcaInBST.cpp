// LC 235: Lowest Common Ancestor of a Binary Search Tree (Easy)
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Approach: Iterative binary search path traversal.
//           Since it's a BST, if p and q are on the same side of the current node,
//           we move down in that direction. The first node where they split (or one matches) is the LCA.
// Time: O(H) where H is the height of the tree (O(log N) for balanced trees, O(N) for skewed trees).
// Space: O(1) auxiliary space.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }
        return curr;
    }
};

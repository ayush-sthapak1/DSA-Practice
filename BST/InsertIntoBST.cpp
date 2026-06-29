// LC 701: Insert into a Binary Search Tree (Medium)
// Approach: Iterative tree search down to the insertion point.
// Time: O(H) where H is the height of the tree (O(log N) average, O(N) worst case).
// Space: O(1) auxiliary space.

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if (root == nullptr) return temp;

        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->val > val) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = temp;
                    break;
                }
            } else {
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = temp;
                    break;
                }
            }
        }
        return root;
    }
};

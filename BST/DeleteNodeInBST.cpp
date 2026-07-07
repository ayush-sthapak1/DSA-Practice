// LC 450: Delete Node in a BST (Medium)
// Link: https://leetcode.com/problems/delete-node-in-a-bst/
// Approach: Iterative in-place pointer rewiring.
//           For nodes with two children, we connect the right child to the rightmost 
//           node of the left subtree (inorder predecessor) to maintain the BST properties.
// Time: O(H) where H is the height of the tree (O(log N) average, O(N) worst case).
// Space: O(1) auxiliary space.

class Solution {
private:
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        
        if (root->val == key) {
            return helper(root);
        }
        
        TreeNode* dummy = root;
        while (root != nullptr) {
            if (root->val > key) {
                if (root->left != nullptr && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != nullptr && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};

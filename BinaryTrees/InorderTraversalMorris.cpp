// LC 94: Binary Tree Inorder Traversal (Easy) - Morris Traversal Version
// Approach: Threaded Binary Tree (Morris Traversal) for O(1) Auxiliary Space
// Time: O(N) linear-time
// Space: O(1) auxiliary - no stack, no recursion!

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr != nullptr) {
            // Case 1: If there is no left subtree, visit the node and move right
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } 
            // Case 2: Left subtree exists, find inorder predecessor to create/break thread
            else {
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                // Subcase A: Thread does not exist, establish it and move left
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } 
                // Subcase B: Thread exists, break it, visit the root, and move right
                else {
                    prev->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};

// LC 144: Binary Tree Preorder Traversal (Easy)
// Approach: Morris Preorder Traversal (threaded binary tree).
// Time: O(N) where N is the number of nodes (each edge is traversed at most 3 times).
// Space: O(1) auxiliary space (modifies tree pointers dynamically and restores them).

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                // If predecessor's right is null, establish thread and visit root now (Preorder)
                if (prev->right == nullptr) {
                    prev->right = curr;
                    result.push_back(curr->val);
                    curr = curr->left;
                } 
                // If thread already exists, destroy thread and move to right child
                else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};

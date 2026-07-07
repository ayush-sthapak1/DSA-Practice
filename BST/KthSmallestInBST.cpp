// LC 230: Kth Smallest Element in a BST (Medium)
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Approach: Morris Inorder Traversal to achieve O(1) space.
//           We traverse the tree and increment count on visiting. 
//           We let the traversal run fully to clean up temporary threads and prevent tree corruption.
// Time: O(N) where N is the number of nodes in the BST.
// Space: O(1) auxiliary space.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int count = 0;
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                count++;
                if (count == k) {
                    ans = curr->val;
                }
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                // Establish thread link
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } 
                // Destroy thread link and visit root
                else {
                    prev->right = nullptr;
                    count++;
                    if (count == k) {
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

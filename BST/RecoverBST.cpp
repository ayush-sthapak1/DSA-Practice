// LC 99: Recover Binary Search Tree (Medium)
// Approach: Morris Inorder Traversal to achieve strictly O(1) auxiliary space.
//           Tracks the previously visited node 'prev' to find sorted violations on the fly.
// Time: O(N) where N is the number of nodes in the BST.
// Space: O(1) auxiliary space (no recursion or stack frames).

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Visit current node
                if (prev != nullptr && prev->val > curr->val) {
                    if (first == nullptr) {
                        first = prev;
                        middle = curr;
                    } else {
                        last = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                // Establish thread link
                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } 
                // Destroy thread link and visit current node
                else {
                    pred->right = nullptr;
                    if (prev != nullptr && prev->val > curr->val) {
                        if (first == nullptr) {
                            first = prev;
                            middle = curr;
                        } else {
                            last = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Swap the values of the two mismatched nodes
        if (last != nullptr) {
            int temp = last->val;
            last->val = first->val;
            first->val = temp;
        } else if (first != nullptr && middle != nullptr) {
            int temp = middle->val;
            middle->val = first->val;
            first->val = temp;
        }
    }
};

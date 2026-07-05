// GFG: Inorder Successor in BST (Easy/Medium)
// Approach: Iterative binary search (Ceil logic).
// Time: O(H) where H is the height of the tree (O(log N) average, O(N) worst case).
// Space: O(1) auxiliary space.

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        int ans = -1;
        
        while (root != nullptr) {
            if (root->data <= k->data) {
                root = root->right;
            } else {
                ans = root->data;
                root = root->left;
            }
        }
        return ans;
    }
};

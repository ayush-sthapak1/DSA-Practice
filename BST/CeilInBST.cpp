// GFG: Ceil in BST (Medium)
// Approach: Iterative binary search on BST.
// Time: O(H) where H is the tree height (O(log N) average, O(N) worst case).
// Space: O(1) auxiliary space.

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ans = -1;
        
        while (root != nullptr) {
            if (root->data == x) {
                return x;
            } else if (root->data < x) {
                root = root->right;
            } else {
                ans = root->data;
                root = root->left;
            }
        }
        return ans;
    }
};

// LC 114: Flatten Binary Tree to Linked List (Medium)
// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Approach: Reverse Preorder DFS (Right -> Left -> Root) tracking a member variable 'prev'.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.

class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        // Traverse in reverse preorder so that we visit nodes from right to left
        flatten(root->right);
        flatten(root->left);

        // Rewire pointers
        root->right = prev;
        root->left = nullptr;
        
        // Update prev pointer
        prev = root;
    }
};

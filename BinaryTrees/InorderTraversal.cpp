// LC 94: Binary Tree Inorder Traversal (Easy)
// Approach: Recursive Depth-First Search (DFS) - Left -> Root -> Right
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (recursion stack depth)

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        // Recurse: Visit Left subtree
        inOrder(root->left, result);

        // Action: Visit the Root
        result.push_back(root->val);

        // Recurse: Visit Right subtree
        inOrder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inOrder(root, result);
        return result;
    }
};

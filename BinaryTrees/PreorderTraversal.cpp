// LC 144: Binary Tree Preorder Traversal (Easy)
// Approach: Recursive Depth-First Search (DFS) - Root -> Left -> Right
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (recursion stack depth)

class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        // Action: Visit the Root
        result.push_back(root->val);

        // Recurse: Visit Left subtree
        preOrder(root->left, result);

        // Recurse: Visit Right subtree
        preOrder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preOrder(root, result);
        return result;
    }
};

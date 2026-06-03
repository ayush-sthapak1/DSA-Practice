// LC 145: Binary Tree Postorder Traversal (Easy)
// Approach: Recursive Depth-First Search (DFS) - Left -> Right -> Root
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (recursion stack depth)

class Solution {
public:
    void postOrder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        // Recurse: Visit Left subtree
        postOrder(root->left, result);

        // Recurse: Visit Right subtree
        postOrder(root->right, result);

        // Action: Visit the Root
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrder(root, result);
        return result;
    }
};

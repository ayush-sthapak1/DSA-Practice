// LC 144: Binary Tree Preorder Traversal (Easy) - Iterative Version
// Approach: Iterative DFS using an explicit Stack (Root -> Left -> Right)
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (explicit stack size)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();

            // Visit the root
            result.push_back(curr->val);

            // Push right child first so that left child is processed first (LIFO)
            if (curr->right != nullptr) {
                s.push(curr->right);
            }
            if (curr->left != nullptr) {
                s.push(curr->left);
            }
        }

        return result;
    }
};

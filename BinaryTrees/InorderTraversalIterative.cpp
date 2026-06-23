// LC 94: Binary Tree Inorder Traversal (Easy) - Iterative Version
// Approach: Iterative DFS using an explicit Stack (Left -> Root -> Right)
// Time: O(N) where N is the number of nodes
// Space: O(H) where H is the height of the tree (explicit stack size)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            // 1. Go to the leftmost node of the current subtree
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            
            // 2. Process the leftmost node (top of stack)
            curr = s.top();
            s.pop();
            result.push_back(curr->val);
    
            // 3. Move to the right child
            curr = curr->right;
        }
        
        return result;
    }
};

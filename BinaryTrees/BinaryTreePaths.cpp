// LC 257: Binary Tree Paths (Easy)
// Approach: Backtracking DFS with a shared path vector to avoid copying strings.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.

class Solution {
public:
    void helper(TreeNode* root, vector<int>& path, vector<string>& result) {
        path.push_back(root->val);
        
        // If it's a leaf node, build the string path
        if (root->left == nullptr && root->right == nullptr) {
            string s = "";
            for (int i = 0; i < path.size(); i++) {
                s += to_string(path[i]);
                if (i != path.size() - 1) s += "->";
            }
            result.push_back(s);
        }
        
        if (root->left) {
            helper(root->left, path, result);
        }
        if (root->right) {
            helper(root->right, path, result);
        }
        
        // Backtrack
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> path;
        vector<string> result;
        helper(root, path, result);
        return result;
    }
};

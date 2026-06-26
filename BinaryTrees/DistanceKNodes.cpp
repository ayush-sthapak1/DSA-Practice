// LC 863: All Nodes Distance K in Binary Tree (Medium)
// Approach: Path-based DFS.
//           1. Find the path from root to target node (stores up to H elements).
//           2. Traverse down from target to collect nodes at distance K.
//           3. For each ancestor on the path, calculate distance to target and traverse downwards 
//              into its other child's subtree (blocking the branch containing the target).
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for path storage and recursion stack where H is the height of the tree.

class Solution {
private:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr) {
            return false;
        }
        path.push_back(root);
        if (root == target) {
            return true;
        }
        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    void findKDown(TreeNode* node, int k, vector<int>& result) {
        if (node == nullptr || k < 0) return;
        if (k == 0) {
            result.push_back(node->val);
            return;
        }
        findKDown(node->left, k - 1, result);
        findKDown(node->right, k - 1, result);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        findPath(root, target, path);
        vector<int> result;

        int n = path.size();
        for (int i = 0; i < n - 1; i++) {
            // If the ancestor itself is at distance K from target, include it
            if (n - 1 - i == k) {
                result.push_back(path[i]->val);
            }
            
            // Search down into the branch that does NOT contain the target
            if (path[i]->left != path[i + 1]) {
                findKDown(path[i]->left, k - n + i, result);
            }
            if (path[i]->right != path[i + 1]) {
                findKDown(path[i]->right, k - n + i, result);
            }
        }
        
        // Search down from target itself
        findKDown(target, k, result);
        
        return result;
    }
};

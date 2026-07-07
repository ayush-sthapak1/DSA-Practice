// LC 2385: Amount of Time for Binary Tree to Be Infected (Medium)
// Link: https://www.geeksforgeeks.org/problems/burning-tree/1
// GFG: Burning Tree (Hard)
// Approach: Path-based DFS. 
//           We trace the path from root to the start/target node, then find the maximum distance 
//           by checking the depth of target's own subtree and each ancestor's non-target child subtree.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for path storage and recursion stack where H is the height of the tree.

class Solution {
private:
    bool findPath(TreeNode* root, int target, vector<TreeNode*>& path) {
        if (root == nullptr) {
            return false;
        }
        path.push_back(root);
        if (root->val == target) {
            return true;
        }
        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        vector<TreeNode*> path;
        findPath(root, start, path);
        int time = 0;

        int n = path.size();

        // For each ancestor, check the max depth of the non-target subtree
        for (int i = 0; i < n - 1; i++) {
            if (path[i]->left != path[i + 1]) {
                time = max(time, maxDepth(path[i]->left) + n - i - 1);
            }
            if (path[i]->right != path[i + 1]) {
                time = max(time, maxDepth(path[i]->right) + n - i - 1);
            }
        }
        
        // Check the subtree of the target node itself
        time = max(time, maxDepth(path[n - 1]) - 1);

        return time;
    }
};

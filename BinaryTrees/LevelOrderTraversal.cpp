// LC 102: Binary Tree Level Order Traversal (Medium)
// Approach: Breadth-First Search (BFS) using a Queue with Queue-Size Level Grouping
// Time: O(N) where N is the number of nodes
// Space: O(W) where W is the maximum width of the tree (queue size at the leaf level, at most N/2)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Base case: If tree is empty, return empty 2D vector
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> q;
        vector<vector<int>> result;
        
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size(); // Number of nodes at the current level
            vector<int> currLvl;

            // Process all nodes at the current level
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                currLvl.push_back(curr->val);
                
                // Push left and right children if they exist
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            
            // Append the current level's values to the result
            result.push_back(currLvl);
        }

        return result;
    }
};

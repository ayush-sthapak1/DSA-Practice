// LC 987: Vertical Order Traversal of Binary Tree (Hard)
// Approach: Coordinate-based DFS with two-pass logic. 
//           Pass 1: Find min/max column index dynamically.
//           Pass 2: Collect nodes into 2D vector offset using (row, value) pairs. Sort each column.
// Time: O(N log(N/K)) where K is the number of columns (due to sorting each column vector)
// Space: O(N) auxiliary space to store coordinate mappings and recursion stack


class Solution {
public:
    void findMinMax(TreeNode* root, int col, int& minCol, int& maxCol) {
        if (root == nullptr) return;
        
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);
        
        findMinMax(root->left, col - 1, minCol, maxCol);
        findMinMax(root->right, col + 1, minCol, maxCol);
    }

    void helper(TreeNode* root, vector<vector<pair<int, int>>>& order, int row, int col, int minCol) {
        if (root == nullptr) return;

        helper(root->left, order, row + 1, col - 1, minCol);
        order[col - minCol].push_back({row, root->val});
        helper(root->right, order, row + 1, col + 1, minCol);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minCol = 0, maxCol = 0;
        findMinMax(root, 0, minCol, maxCol);

        vector<vector<pair<int, int>>> order(maxCol - minCol + 1);
        helper(root, order, 0, 0, minCol);
        
        for (int i = 0; i < order.size(); i++) {
            sort(order[i].begin(), order[i].end());
        }
        
        vector<vector<int>> result(maxCol - minCol + 1);
        for (int i = 0; i < order.size(); i++) {
            for (int j = 0; j < order[i].size(); j++) {
                result[i].push_back(order[i][j].second);
            }
        }
        return result;
    }
};

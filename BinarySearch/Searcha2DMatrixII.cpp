// LeetCode 240: Search a 2D Matrix II
// Approach: Staircase search (start from top-right)
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        // Start from top-right corner
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;      // move left
            } else {
                row++;      // move down
            }
        }
        return false;
    }
};

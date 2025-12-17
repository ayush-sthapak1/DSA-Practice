// LeetCode 73: Set Matrix Zeroes
// Approach: Use first row and first column as markers to store zero information
// Time Complexity: O(n * m)
// Space Complexity: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool row0 = false, col0 = false;

        // Check if first row contains any zero
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
            }
        }

        // Check if first column contains any zero
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
            }
        }

        // Use first row and column as markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Set zeroes based on markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (row0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if (col0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

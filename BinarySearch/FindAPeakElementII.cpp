// LeetCode 1901: Find a Peak Element II
// Approach: Binary search on columns + max element scan
// Time Complexity: O(m log n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int midCol = low + (high - low) / 2;

            // Find row index of maximum element in midCol
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int left  = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int right = (midCol + 1 < n)  ? mat[maxRow][midCol + 1] : -1;

            // Check if current element is a peak
            if (mat[maxRow][midCol] > left && mat[maxRow][midCol] > right) {
                return {maxRow, midCol};
            }
            // Move to the side with larger neighbor
            else if (left > mat[maxRow][midCol]) {
                high = midCol - 1;
            } else {
                low = midCol + 1;
            }
        }
        return {-1, -1}; // unreachable for valid inputs
    }
};

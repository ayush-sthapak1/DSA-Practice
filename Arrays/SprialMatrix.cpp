// LeetCode 54: Spiral Matrix
// Approach: Use four boundaries (top, bottom, left, right) and
// traverse the matrix layer by layer in spiral order
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)  -> output array

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        vector<int> ans((bottom + 1) * (right + 1));
        int k = 0;

        while (top <= bottom && left <= right) {

            // Traverse top row
            for (int j = left; j <= right; j++) {
                ans[k++] = matrix[top][j];
            }
            top++;

            // Traverse right column
            for (int i = top; i <= bottom; i++) {
                ans[k++] = matrix[i][right];
            }
            right--;

            if (top > bottom || left > right) break;

            // Traverse bottom row
            for (int j = right; j >= left; j--) {
                ans[k++] = matrix[bottom][j];
            }
            bottom--;

            // Traverse left column
            for (int i = bottom; i >= top; i--) {
                ans[k++] = matrix[i][left];
            }
            left++;
        }

        return ans;
    }
};

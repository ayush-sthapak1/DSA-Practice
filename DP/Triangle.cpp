// LC 120: Triangle (Medium)
// Link: https://leetcode.com/problems/triangle/
// Approach: Top-Down Space-Optimized 1D Dynamic Programming.
//           Recurrence: curr[j] = triangle[i][j] + min(prev[j], prev[j-1]).
// Time: O(N^2) where N is the number of rows in the triangle.
// Space: O(N) auxiliary space.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Base case: Row 0 has only one element
        vector<int> prev = {triangle[0][0]};

        // Top-down space-optimized tabulation from row 1 to n - 1
        for (int i = 1; i < n; i++) {
            int rowSize = triangle[i].size();
            vector<int> curr(rowSize, 0);

            for (int j = 0; j < rowSize; j++) {
                int up = INT_MAX;
                int leftUp = INT_MAX;

                // Move directly down from (i-1, j)
                if (j < prev.size()) {
                    up = triangle[i][j] + prev[j];
                }

                // Move diagonally down-right from (i-1, j-1)
                if (j - 1 >= 0) {
                    leftUp = triangle[i][j] + prev[j - 1];
                }

                curr[j] = min(up, leftUp);
            }
            prev = curr; // Move to next row
        }

        // The answer is the minimum value in the last row
        return *min_element(prev.begin(), prev.end());
    }
};

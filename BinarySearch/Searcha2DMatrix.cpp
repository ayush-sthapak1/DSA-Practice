// LeetCode 74: Search a 2D Matrix
// Approach: Binary search on rows, then binary search within row
// Time Complexity: O(log m + log n)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lowR = 0, highR = m - 1;

        // Binary search to find the correct row
        while (lowR <= highR) {
            int midR = lowR + (highR - lowR) / 2;

            if (matrix[midR][n - 1] < target) {
                lowR = midR + 1;
            } else {
                highR = midR - 1;
            }
        }

        // If target is greater than all elements
        if (lowR >= m) return false;

        int row = lowR;

        // Binary search inside the selected row
        int lowC = 0, highC = n - 1;
        while (lowC <= highC) {
            int midC = lowC + (highC - lowC) / 2;

            if (matrix[row][midC] == target)
                return true;
            else if (matrix[row][midC] > target)
                highC = midC - 1;
            else
                lowC = midC + 1;
        }
        return false;
    }
};

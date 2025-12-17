// LeetCode 118: Pascal's Triangle
// Approach: Build each row using values from the previous row
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)  -> storing the entire triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);

        for (int i = 0; i < numRows; i++) {
            v[i].resize(i + 1);
            for (int j = 0; j <= i; j++) {
                // First and last elements of each row are 1
                if (j == 0 || j == i) {
                    v[i][j] = 1;
                } else {
                    // Sum of two elements from the previous row
                    v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
                }
            }
        }

        return v;
    }
};

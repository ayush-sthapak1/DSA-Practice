// GFG: Geek's Training / Ninja's Training (Medium)
// Link: https://www.geeksforgeeks.org/problems/geeks-training/1
// Approach: Space-Optimized Dynamic Programming using two 1D vectors of size 4.
// Time: O(N * 4 * 3) = O(N) where N is number of days.
// Space: O(1) auxiliary space (uses only two vectors of size 4).

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> prev(4), curr(4);

        // Base Case for day 0
        prev[0] = max(mat[0][1], mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max({mat[0][0], mat[0][1], mat[0][2]});

        // Space-Optimized Tabulation for day 1 to n - 1
        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                curr[last] = 0;

                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        curr[last] = max(curr[last], mat[day][task] + prev[task]);
                    }
                }
            }

            prev = curr; // Move to next day
        }

        return prev[3]; // 3 represents no task restriction for the final day
    }
};

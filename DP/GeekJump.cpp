// GFG: Geek Jump / Frog Jump (Easy/Medium)
// Link: https://www.geeksforgeeks.org/problems/geek-jump/1
// Approach: Space-Optimized Dynamic Programming. At each step i, min cost is 
//           min(costFrom(i-1) + |h[i] - h[i-1]|, costFrom(i-2) + |h[i] - h[i-2]|).
// Time: O(N) where N is the number of stairs.
// Space: O(1) auxiliary space.

class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n <= 1) return 0;

        int prev2 = 0;                          // Cost to reach index 0
        int prev1 = abs(height[1] - height[0]); // Cost to reach index 1

        for (int i = 2; i < n; i++) {
            int jumpOne = prev1 + abs(height[i] - height[i - 1]);
            int jumpTwo = prev2 + abs(height[i] - height[i - 2]);

            int curr = min(jumpOne, jumpTwo);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

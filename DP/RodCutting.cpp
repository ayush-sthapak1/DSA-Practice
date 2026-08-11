// GFG: Rod Cutting (Medium)
// Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// Approach: 1D Unbounded Knapsack DP.
//           dp[i] stores max revenue for rod of length i.
//           Recurrence: dp[i] = max(dp[i], price[j - 1] + dp[i - j]) for cut length j from 1 to i.
// Time: O(N^2) where N is the length of the rod.
// Space: O(N) auxiliary space.

class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        // dp[i] stores max value for rod of length i
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        
        return dp[n];
    }
};

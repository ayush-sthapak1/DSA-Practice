// LC 322: Coin Change (Medium)
// Link: https://leetcode.com/problems/coin-change/
// Approach: 1D Unbounded Knapsack DP. Forward inner loop allows infinite coin re-use.
//           Recurrence: dp[a] = min(dp[a], 1 + dp[a - coins[i]]).
// Time: O(N * amount) where N is the number of coin denominations.
// Space: O(amount) auxiliary space.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array with 1e9 (infinity sentinel)
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0; // Base case: 0 coins needed to make amount 0

        for (int i = 0; i < coins.size(); i++) {
            // Forward loop allows reusing the same coin multiple times
            for (int a = coins[i]; a <= amount; a++) {
                dp[a] = min(dp[a], 1 + dp[a - coins[i]]);
            }
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};

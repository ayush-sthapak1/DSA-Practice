// LC 123: Best Time to Buy and Sell Stock III (Hard)
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Approach: 3D DP Tabulation (At Most 2 Transactions).
//           State: dp[idx][buy][cap] where cap represents remaining allowed transactions (max 2).
//           On Sell: Decrement cap to cap - 1.
// Time: O(N * 2 * 3) = O(N) where N is the number of days.
// Space: O(N * 2 * 3) = O(N) auxiliary space.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // dp[idx][buy][cap]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Iterate backwards from day n-1 to day 0
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                        // Option 1: Buy today (cost -prices[idx], moves to sell state)
                        // Option 2: Skip buying today
                        dp[idx][buy][cap] = max(-prices[idx] + dp[idx + 1][0][cap], 
                                                dp[idx + 1][1][cap]);
                    } else {
                        // Option 1: Sell today (gain +prices[idx], moves to buy state & decrements cap)
                        // Option 2: Skip selling today
                        dp[idx][buy][cap] = max(prices[idx] + dp[idx + 1][1][cap - 1], 
                                                dp[idx + 1][0][cap]);
                    }
                }
            }
        }

        // Return max profit starting at day 0, with buy permission (buy = 1), and 2 transactions left (cap = 2)
        return dp[0][1][2];
    }
};

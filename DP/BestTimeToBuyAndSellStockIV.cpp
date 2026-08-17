// LC 188: Best Time to Buy and Sell Stock IV (Hard)
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Approach: General 3D DP Tabulation (At Most K Transactions).
//           State: dp[idx][buy][cap] where cap represents remaining allowed transactions (max k).
// Time: O(N * K) where N is number of days and K is max allowed transactions.
// Space: O(N * K) auxiliary space.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // dp[idx][buy][cap]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Iterate backwards from day n-1 to day 0
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
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

        // Return max profit starting at day 0 with buy permission (buy = 1) and k capacity
        return dp[0][1][k];
    }
};

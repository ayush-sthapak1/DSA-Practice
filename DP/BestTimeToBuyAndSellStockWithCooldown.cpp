// LC 309: Best Time to Buy and Sell Stock with Cooldown (Medium)
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Approach: Space-Optimized State-Machine DP using 2x2 matrices.
//           States: j = buy status (1 = can buy, 0 = can sell), k = cooldown status (1 = in cooldown, 0 = normal).
//           On Sell: Transitions to ahead[1][1] (cooldown = 1) forcing 1 day wait before next buy.
// Time: O(N) where N is the number of days.
// Space: O(1) auxiliary space (using two 2x2 matrices).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // curr[buy][cooldown] and ahead[buy][cooldown]
        vector<vector<int>> curr(2, vector<int>(2, 0));
        vector<vector<int>> ahead(2, vector<int>(2, 0));

        // Iterate backwards from last day to day 0
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (k == 1) {
                        // Cooldown active: must skip today and reset cooldown for next day
                        curr[j][k] = ahead[1][0];
                    }
                    else if (j == 1) {
                        // Allowed to buy: choose max of buying today vs skipping
                        curr[j][k] = max(-prices[i] + ahead[0][0], ahead[1][0]);
                    }
                    else {
                        // Allowed to sell: choose max of selling today (triggers cooldown) vs skipping
                        curr[j][k] = max(prices[i] + ahead[1][1], ahead[0][0]);
                    }
                }
            }
            ahead = curr; // Move to previous day
        }
        
        // Final answer starting at day 0 with buy permission (j = 1) and no cooldown (k = 0)
        return curr[1][0];
    }
};

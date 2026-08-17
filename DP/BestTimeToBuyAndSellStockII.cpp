// LC 122: Best Time to Buy and Sell Stock II (Medium)
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Approach: State-Machine DP (Unlimited Transactions).
//           currBuy = max(-prices[i] + aheadNotBuy, aheadBuy)
//           currNotBuy = max(prices[i] + aheadBuy, aheadNotBuy)
// Time: O(N) where N is the number of days.
// Space: O(1) auxiliary space.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Base cases for day N (after market closes, max profit is 0)
        int aheadBuy = 0;
        int aheadNotBuy = 0;

        // Iterate backwards from last day to day 0
        for (int i = prices.size() - 1; i >= 0; i--) {

            int currBuy = max(
                -prices[i] + aheadNotBuy, // Option 1: Buy today
                aheadBuy                  // Option 2: Skip today
            );

            int currNotBuy = max(
                prices[i] + aheadBuy,     // Option 1: Sell today
                aheadNotBuy               // Option 2: Skip today
            );

            // Shift states for next iteration (previous day)
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        // Final answer starting at day 0 with permission to buy
        return aheadBuy;
    }
};

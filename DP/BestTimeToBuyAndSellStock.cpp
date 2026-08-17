// LC 121: Best Time to Buy and Sell Stock (Easy)
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: Single-pass Greedy / DP. Track minPrice seen so far and update max profit (price - minPrice).
// Time: O(N) where N is the number of days.
// Space: O(1) auxiliary space.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = INT_MIN;
        int minPrice = INT_MAX;

        // Iterate through daily prices
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // Found a lower buying price
            } else {
                if (ans < price - minPrice) {
                    ans = price - minPrice; // Update max profit if selling today
                }
            }
        }
        
        return ans < 0 ? 0 : ans; // Return 0 if no profit can be made
    }
};

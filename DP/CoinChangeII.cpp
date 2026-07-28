// LC 518: Coin Change II (Medium)
// Link: https://leetcode.com/problems/coin-change-ii/
// Approach: 1D Unbounded Knapsack DP (Counting Combinations).
//           Outer loop over coins + forward inner loop over amounts.
//           Recurrence: dp[a] = dp[a] + dp[a - coins[i]].
// Time: O(N * amount) where N is the number of coin denominations.
// Space: O(amount) auxiliary space.

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[a] stores the number of combinations to form amount 'a'
        vector<unsigned int> dp(amount + 1, 0);
        
        dp[0] = 1; // Base case: 1 way to form amount 0 (using no coins)

        // Outer loop over coins ensures order doesn't matter (counts combinations, not permutations)
        for (int i = 0; i < coins.size(); i++) {
            // Forward inner loop enables infinite reuse of coin[i]
            for (int a = coins[i]; a <= amount; a++) {
                dp[a] = dp[a] + dp[a - coins[i]];
            }
        }

        return dp[amount];
    }
};

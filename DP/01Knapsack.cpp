// GFG: 0/1 Knapsack Problem (Medium)
// Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0917/1
// Approach: Ultimate Space-Optimized 1D Dynamic Programming.
//           Iterating weight 'w' backwards from W down to wt[i] ensures items are picked at most once.
//           Recurrence: dp[w] = max(dp[w], val[i] + dp[w - wt[i]]).
// Time: O(N * W) where N is the number of items and W is max capacity.
// Space: O(W) auxiliary space (single 1D vector).

class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        // 1D DP array initialized to 0
        vector<int> dp(W + 1, 0);
        
        for (int i = 0; i < n; i++) {
            // Loop backwards from capacity W down to wt[i]
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        
        return dp[W];
    }
};

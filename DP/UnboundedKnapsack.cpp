// GFG: Knapsack with Duplicate Items / Unbounded Knapsack (Medium)
// Link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Approach: 1D In-Place Unbounded Knapsack DP.
//           Forward loop allows item i to be reused infinitely at higher capacities.
//           Recurrence: dp[W] = max(dp[W], val[i] + dp[W - wt[i]]).
// Time: O(N * capacity) where N is number of items and capacity is max weight.
// Space: O(capacity) auxiliary space.

class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> prev(capacity + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            // Forward loop allows reusing item i multiple times
            for (int W = 0; W <= capacity; W++) {
                int notTake = prev[W];
                int take = 0;
                
                if (wt[i] <= W) {
                    take = val[i] + prev[W - wt[i]]; // Uses updated prev for current item
                }
                
                prev[W] = max(take, notTake);
            }
        }
        
        return prev[capacity];
    }
};

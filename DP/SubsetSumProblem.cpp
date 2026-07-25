// GFG: Subset Sum Problem (Medium)
// Link: https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
// Approach: Space-Optimized 1D Dynamic Programming (0/1 Knapsack Pick/Not-Pick Pattern).
//           Recurrence: curr[target] = prev[target] (not-pick) || prev[target - arr[i]] (pick).
// Time: O(N * sum) where N is array size and sum is the target sum.
// Space: O(sum) auxiliary space.

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        if (sum == 0) return true;
        
        vector<bool> prev(sum + 1, false), curr(sum + 1, false);
        
        // Base case: Target sum 0 is always achievable (empty subset)
        prev[0] = true;
        curr[0] = true;
        
        // Base case for element at index 0
        if (arr[0] <= sum) {
            prev[arr[0]] = true;
        }
        
        // Space-optimized DP tabulation
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool notPick = prev[target];
                bool pick = false;
                
                if (target - arr[i] >= 0) {
                    pick = prev[target - arr[i]];
                }
                
                curr[target] = pick || notPick;
            }
            prev = curr; // Move to next element
        }
        
        return prev[sum];
    }
};

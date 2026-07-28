// GFG: Count Subsets with Sum K / Perfect Sum Problem (Medium)
// Link: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// Approach: Space-Optimized 1D Dynamic Programming (Counting Subsets).
//           Recurrence: curr[sum] = (notTake + take) % MOD.
//           Handles zeros by setting prev[0] = 2 if arr[0] == 0 and running sum from 0 to target.
// Time: O(N * target) where N is array size and target is requested sum.
// Space: O(target) auxiliary space.

class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> prev(target + 1, 0);

        // Base Case for index 0
        if (arr[0] == 0) {
            prev[0] = 2; // 2 ways to get sum 0 (pick 0 or don't pick 0)
        } else {
            prev[0] = 1; // 1 way to get sum 0 (empty subset)
            if (arr[0] <= target) {
                prev[arr[0]] = 1;
            }
        }

        // Space-optimized tabulation
        for (int i = 1; i < n; i++) {
            vector<int> curr(target + 1, 0);
            
            // Loop sum from 0 to target to correctly count zero elements
            for (int sum = 0; sum <= target; sum++) {
                int notTake = prev[sum];
                int take = 0;

                if (sum >= arr[i]) {
                    take = prev[sum - arr[i]];
                }

                curr[sum] = (take + notTake);
            }
            prev = curr; // Shift state to next element
        }

        return prev[target];
    }
};

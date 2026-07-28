// GFG: Partitions With Given Difference (Medium)
// Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
// Approach: Reduction to Count Subsets with Sum K.
//           S1 = (totalSum + diff) / 2. Count subsets with target = S1.
// Time: O(N * target) where target = (totalSum + diff) / 2.
// Space: O(target) auxiliary space.

class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        
        for (int i : arr) {
            totalSum += i;
        }
        
        // Edge cases: diff exceeds totalSum or (totalSum + diff) is odd
        if (totalSum < diff || (totalSum + diff) % 2 != 0) {
            return 0;
        }
        
        int target = (totalSum + diff) / 2;
        vector<int> prev(target + 1, 0);
        
        // Base case for index 0
        if (arr[0] == 0) {
            prev[0] = 2; // 2 ways (pick 0 or don't pick 0)
        } else {
            prev[0] = 1;
            if (arr[0] <= target) {
                prev[arr[0]] = 1;
            }
        }
        
        // Space-optimized DP tabulation
        for (int i = 1; i < n; i++) {
            vector<int> curr(target + 1, 0);
            for (int sum = 0; sum <= target; sum++) {
                int notTake = prev[sum];
                int take = 0;
                
                if (arr[i] <= sum) {
                    take = prev[sum - arr[i]];
                }
                
                curr[sum] = (take + notTake) ;
            }
            prev = curr;
        }
        
        return prev[target];
    }
};

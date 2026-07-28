// LC 494: Target Sum (Medium)
// Link: https://leetcode.com/problems/target-sum/
// Approach: Reduction to Count Subsets with Sum K.
//           S1 = (totalSum + target) / 2. Count subsets with sum = S1.
// Time: O(N * S1) where S1 = (totalSum + target) / 2.
// Space: O(S1) auxiliary space.

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge cases: Target exceeds totalSum, or (totalSum + target) is odd or negative
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0 || (totalSum + target) < 0) {
            return 0;
        }

        int sum = (totalSum + target) / 2;

        vector<int> prev(sum + 1, 0);

        // Base case for index 0 (handles zeros correctly)
        if (nums[0] == 0) {
            prev[0] = 2; // 2 ways (pick 0 or don't pick 0)
        } else {
            prev[0] = 1;
            if (nums[0] <= sum) {
                prev[nums[0]] = 1;
            }
        }

        // Space-optimized DP tabulation
        for (int i = 1; i < n; i++) {
            vector<int> curr(sum + 1, 0);
            for (int j = 0; j <= sum; j++) {
                int notTake = prev[j];

                int take = 0;
                if (j >= nums[i]) {
                    take = prev[j - nums[i]]; 
                }

                curr[j] = take + notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
};

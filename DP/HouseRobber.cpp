// LC 198: House Robber / Max Sum of Non-Adjacent Elements (Medium)
// Link: https://leetcode.com/problems/house-robber/
// Approach: Space-Optimized Dynamic Programming (Pick vs Not-Pick pattern).
//           dp[i] = max(nums[i] + dp[i-2], dp[i-1]).
// Time: O(N) where N is the number of houses.
// Space: O(1) auxiliary space.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev2 = 0;       // Max money robbed up to i - 2
        int prev1 = nums[0]; // Max money robbed up to i - 1

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2; // Rob house i (add to i - 2 max)
            int notPick = prev1;        // Skip house i (keep i - 1 max)

            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

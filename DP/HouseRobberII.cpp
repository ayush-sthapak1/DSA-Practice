// LC 213: House Robber II (Medium)
// Link: https://leetcode.com/problems/house-robber-ii/
// Approach: Split circular array into 2 linear House Robber subproblems:
//           1) Range [0, n-2] (exclude last house)
//           2) Range [1, n-1] (exclude first house)
//           Result is max(robRange(0, n-2), robRange(1, n-1)).
// Time: O(N) where N is the number of houses.
// Space: O(1) auxiliary space.

class Solution {
private:
    // Helper function to run space-optimized House Robber on a range [start, end]
    int robRange(const vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Rob from first house up to second-to-last house
        int ans1 = robRange(nums, 0, n - 2);
        // Case 2: Rob from second house up to last house
        int ans2 = robRange(nums, 1, n - 1);

        return max(ans1, ans2);
    }
};

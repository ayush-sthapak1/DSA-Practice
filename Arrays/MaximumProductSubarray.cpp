// LeetCode 152: Maximum Product Subarray
// Approach: Track max and min product ending at each index
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxEnd, minEnd);

            maxEnd = max(nums[i], maxEnd * nums[i]);
            minEnd = min(nums[i], minEnd * nums[i]);

            ans = max(ans, maxEnd);
        }
        return ans;
    }
};

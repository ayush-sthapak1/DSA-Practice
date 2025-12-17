// LeetCode 53: Maximum Subarray
// Approach: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

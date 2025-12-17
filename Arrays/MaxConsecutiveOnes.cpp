// LeetCode 485: Max Consecutive Ones
// Approach: Traverse the array and count consecutive ones
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_ones = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                max_ones = max(max_ones, count);
                count = 0;
            }
        }

        // Final check in case array ends with 1s
        max_ones = max(max_ones, count);

        return max_ones;
    }
};

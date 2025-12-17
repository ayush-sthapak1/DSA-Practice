// LeetCode 268: Missing Number
// Approach: Use an auxiliary array to mark seen numbers
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> seen(n + 1, 0);

        // Mark numbers that are present
        for (int x : nums)
            seen[x] = 1;

        // Find the missing number
        for

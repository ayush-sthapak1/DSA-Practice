// LeetCode 31: Next Permutation
// Approach:
// 1. Find the first index i from the right where nums[i] < nums[i + 1]
// 2. Find the smallest element greater than nums[i] to the right
// 3. Swap them
// 4. Reverse the suffix starting at i + 1
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If the array is in descending order, reverse it
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the next larger element to swap with nums[i]
        int smallbigger = n - 1;
        while (nums[smallbigger] <= nums[i]) {
            smallbigger--;
        }

        // Step 3: Swap
        swap(nums[i], nums[smallbigger]);

        // Step 4: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};

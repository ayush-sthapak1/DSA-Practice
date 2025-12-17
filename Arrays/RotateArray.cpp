// LeetCode 189: Rotate Array
// Approach: Reverse the entire array, then reverse first k elements
// and remaining n-k elements
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k >= n

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

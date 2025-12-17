// LeetCode 283: Move Zeroes
// Approach: Two pointers to move all non-zero elements forward
// while maintaining their relative order
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0; // Pointer to place the next non-zero element

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

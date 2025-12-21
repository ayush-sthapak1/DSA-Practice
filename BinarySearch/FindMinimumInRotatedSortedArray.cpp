// LeetCode 153: Find Minimum in Rotated Sorted Array
// Approach: Binary search with early exit for sorted segment
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        if (nums.size() == 1)
            return nums[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in right half
                low = mid + 1;
            }
            else if (nums[mid] < nums[low]) {
                // Minimum is in left half (including mid)
                high = mid;
            }
            else {
                // Subarray is already sorted
                return nums[low];
            }
        }
        return -1; // unreachable for valid input
    }
};

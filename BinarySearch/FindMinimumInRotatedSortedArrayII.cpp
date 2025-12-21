// LeetCode 154: Find Minimum in Rotated Sorted Array II
// Approach: Binary search with duplicate handling
// Time Complexity: O(log n) average, O(n) worst case
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in right half
                low = mid + 1;
            }
            else if (nums[mid] < nums[high]) {
                // Minimum is at mid or in left half
                high = mid;
            }
            else {
                // nums[mid] == nums[high]
                // Cannot decide, shrink search space
                high--;
            }
        }
        return nums[low];
    }
};

// LeetCode 540: Single Element in a Sorted Array
// Approach: Binary search using index parity
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Ensure mid is even
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Single element is on the right
                low = mid + 2;
            } else {
                // Single element is on the left or at mid
                high = mid;
            }
        }
        return nums[low];
    }
};

// LeetCode 162: Find Peak Element
// Approach: Binary search using slope comparison
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        if (nums.size() <= 1)
            return 0;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak exists on the right
                low = mid + 1;
            } else {
                // Peak exists on the left (or at mid)
                high = mid;
            }
        }
        return low;  // index of a peak
    }
};

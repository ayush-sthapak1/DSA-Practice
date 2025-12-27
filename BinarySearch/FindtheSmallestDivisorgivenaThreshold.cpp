// LeetCode 1283: Find the Smallest Divisor Given a Threshold
// Approach: Binary search on divisor
// Time Complexity: O(n log max(nums))
// Space Complexity: O(1)

class Solution {
public:
    bool check(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;
        for (int x : nums) {
            sum += (x + divisor - 1) / divisor;  // integer ceiling
            if (sum > threshold)
                return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller divisor
            } else {
                low = mid + 1;    // divisor too small
            }
        }
        return ans;
    }
};

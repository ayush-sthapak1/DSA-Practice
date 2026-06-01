// LC 1248: Count Number of Nice Subarrays (Medium)
// Approach: Optimal sliding window using the "At Most K" helper function trick.
// Mathematically equivalent to Binary Subarrays With Sum (LC 930) by mapping odd -> 1, even -> 0.
// Time: O(N) dual-pass
// Space: O(1) auxiliary

class Solution {
public:
    int atMost(vector<int>& nums, int x) {
        // A negative odd number constraint has 0 valid subarrays
        if (x < 0) {
            return 0;
        }

        int left = 0;
        int n = nums.size();
        int oddCount = 0;
        int count = 0;

        for (int right = 0; right < n; right++) {
            // 1. Expand the window: count odd numbers
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            // 2. Shrink the window if it violates the "at most x odds" constraint
            while (oddCount > x) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            // 3. Count valid subarrays ending at right
            count += right - left + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

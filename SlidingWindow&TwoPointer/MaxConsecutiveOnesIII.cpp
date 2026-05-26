// LC 1004: Max Consecutive Ones III (Medium)
// Approach: Optimal Sliding Window (Two-Pointer) with Zero Frequency Tracking
// Time: O(N) single-pass
// Space: O(1) auxiliary

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxOnes = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            // 1. Expand the window: count the zero if we hit one
            if (nums[right] == 0) {
                zeroCount++;
            }

            // 2. Shrink the window: if we exceed k flips, slide left forward
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // 3. Now the window is guaranteed to be valid. Record maximum size.
            maxOnes = max(maxOnes, right - left + 1);
        }

        return maxOnes;
    }
};

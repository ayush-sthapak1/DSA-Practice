// LC 930: Binary Subarrays With Sum (Medium)
// Approach: Optimal sliding window using the "At Most K" helper function trick: exactly(K) = atMost(K) - atMost(K - 1)
// Time: O(N) dual-pass
// Space: O(1) auxiliary

class Solution {
public:
    int atMost(vector<int>& nums, int x) {
        // A negative sum constraint has 0 valid subarrays
        if (x < 0) {
            return 0;
        }

        int left = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;

        for (int right = 0; right < n; right++) {
            // 1. Expand the window
            sum += nums[right];

            // 2. Shrink the window if it violates the "at most x" constraint
            while (sum > x) {
                sum -= nums[left];
                left++;
            }

            // 3. Count subarrays ending at right: [left...right], [left+1...right], ...
            count += right - left + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

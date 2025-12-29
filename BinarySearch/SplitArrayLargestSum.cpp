// LeetCode 410: Split Array Largest Sum
// Approach: Binary search on maximum subarray sum
// Time Complexity: O(n log sum(nums))
// Space Complexity: O(1)

class Solution {
public:
    bool check(vector<int>& nums, int k, int maxSum) {
        int subArrays = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= maxSum) {
                sum += x;
            } else {
                subArrays++;
                sum = x;
            }
        }
        return subArrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, k, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller maximum sum
            } else {
                low = mid + 1;    // need larger maximum sum
            }
        }
        return ans;
    }
};

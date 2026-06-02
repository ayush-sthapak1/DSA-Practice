// LC 992: Subarrays with K Different Integers (Hard)
// Approach: Optimal sliding window using the "At Most K" helper function trick.
// Mathematically: exactly(K) = atMost(K) - atMost(K - 1)
// Time: O(N) dual-pass
// Space: O(N) auxiliary (size N+1 frequency array)

class Solution {
public:
    int atMost(vector<int>& nums, int x) {
        // A negative distinct number constraint has 0 valid subarrays
        if (x < 0) {
            return 0;
        }

        int left = 0;
        int n = nums.size();
        int count = 0;
        int dist = 0; // Tracks the number of unique integers in the window
        
        // Frequency array sized safely at n + 1 for 0-indexing
        vector<int> freq(n + 1, 0);

        for (int right = 0; right < n; right++) {
            // 1. Expand the window: count new distinct number
            if (freq[nums[right]] == 0) {
                dist++;
            }
            freq[nums[right]]++;

            // 2. Shrink the window: if unique count exceeds x, slide left forward
            while (dist > x) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    dist--;
                }
                left++;
            }

            // 3. Count valid subarrays ending at right
            count += right - left + 1;
        }
        
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

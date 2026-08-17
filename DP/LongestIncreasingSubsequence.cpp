// LC 300: Longest Increasing Subsequence (Medium)
// Link: https://leetcode.com/problems/longest-increasing-subsequence/
// Contains 3 Approaches:
//   1. 2-Row Space-Optimized DP (Pick/Not-Pick with coordinate shift) - O(N^2) Time, O(N) Space
//   2. 1D DP Tabulation (Ending at index i) - O(N^2) Time, O(N) Space
//   3. Binary Search / Patience Sorting (lower_bound) - O(N log N) Time, O(N) Space

// ============================================================================
// Approach 1: 2-Row Space-Optimized DP (Pick / Not-Pick)
// Time: O(N^2), Space: O(N)
// ============================================================================
class SolutionApproach1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {
                int take = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    take = 1 + prev[idx + 1]; // Coordinate shift: idx + 1
                }
                int notTake = prev[prevIdx + 1]; // Coordinate shift: prevIdx + 1

                curr[prevIdx + 1] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[0]; // prevIdx = -1 corresponds to index 0
    }
};

// ============================================================================
// Approach 2: 1D DP Tabulation (dp[i] = length of LIS ending at index i)
// Time: O(N^2), Space: O(N)
// Useful for tracing / printing the actual LIS sequence.
// ============================================================================
class SolutionApproach2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            int currLen = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    currLen = max(currLen, dp[j] + 1);
                }
            }
            dp[i] = currLen;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// ============================================================================
// Approach 3: Binary Search / Patience Sorting (Optimal)
// Time: O(N log N), Space: O(N)
// ============================================================================
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        temp.push_back(nums[0]);
        int len = 1;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                // Larger than all tails: extend the sequence
                temp.push_back(nums[i]);
                len++;
            } else {
                // Find the first element >= nums[i] and replace it with smaller tail
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        
        return len;
    }
};

// LeetCode 56: Merge Intervals
// Approach: Sort intervals by start time and merge overlapping intervals
// Time Complexity: O(n log n)  -> sorting dominates
// Space Complexity: O(n)       -> output array

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if (n == 0) return ans;

        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Add the first interval
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            // Check for overlap with the last interval in ans
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

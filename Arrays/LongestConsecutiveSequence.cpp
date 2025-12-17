// LeetCode 128: Longest Consecutive Sequence
// Approach: Use an unordered_set to allow O(1) lookups.
// Start counting only from numbers that are the beginning of a sequence
// (i.e., num - 1 does not exist).
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int maxCount = 1;

        for (int num : s) {
            // Start a sequence only if num is the first element
            if (!s.count(num - 1)) {
                int current = num;
                int count = 1;

                while (s.count(current + 1)) {
                    current++;
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};

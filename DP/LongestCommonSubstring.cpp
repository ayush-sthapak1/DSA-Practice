// GFG: Longest Common Substring (Medium)
// Link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// Approach: Space-Optimized 1D Dynamic Programming.
//           On character match: curr[j] = 1 + prev[j-1] (extend contiguous streak).
//           On character mismatch: curr[j] = 0 (reset streak, unlike LCS).
// Time: O(N * M) where N and M are lengths of s1 and s2.
// Space: O(M) auxiliary space.

class Solution {
public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        int maxLen = 0;

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];   // Extend contiguous common streak
                    maxLen = max(maxLen, curr[j]); // Track overall maximum length
                } else {
                    curr[j] = 0;                 // Reset streak on character mismatch
                }
            }
            prev = curr; // Move to next row
        }

        return maxLen;
    }
};

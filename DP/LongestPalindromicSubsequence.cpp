// LC 516: Longest Palindromic Subsequence (Medium)
// Link: https://leetcode.com/problems/longest-palindromic-subsequence/
// Approach: Reduction to LCS. LPS(s) = LCS(s, reverse(s)).
//           Uses 1D space-optimized LCS tabulation between string s and its reverse t.
// Time: O(N^2) where N is the length of string s.
// Space: O(N) auxiliary space.

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end()); // Reverse string s
        
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Run LCS between reversed string t and original string s
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] == s[j - 1]) {
                    curr[j] = 1 + prev[j - 1]; // Character match: extend LCS
                } else {
                    curr[j] = max(prev[j], curr[j - 1]); // Mismatch: max of top or left
                }
            }
            prev = curr; // Move to next row
        }
        
        return prev[n];
    }
};

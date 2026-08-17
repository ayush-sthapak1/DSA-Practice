// LC 1312: Minimum Insertion Steps to Make a String Palindrome (Hard)
// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Approach: Reduction to LPS. Min Insertions = n - LPS(s) = n - LCS(s, reverse(s)).
//           Uses 1D space-optimized LCS tabulation.
// Time: O(N^2) where N is the length of string s.
// Space: O(N) auxiliary space.

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end()); // Reverse string s

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Step 1: Compute LCS(s, reverse(s)) which equals LPS(s)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = 1 + prev[j - 1]; // Character match
                } else {
                    curr[j] = max(prev[j], curr[j - 1]); // Character mismatch
                }
            }
            prev = curr; // Move to next row
        }

        int lpsLength = prev[n];
        
        // Step 2: Min insertions = total length - length of LPS
        return n - lpsLength;
    }
};

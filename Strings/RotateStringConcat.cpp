// LC 796: Rotate String - Concatenation Approach (Easy)
// Link: https://leetcode.com/problems/rotate-string/
// Approach: Concatenate s with itself (s + s). All valid rotations of s exist as contiguous
//           substrings inside (s + s). Check if goal is a substring of (s + s).
// Time: O(N) where N is the length of string s.
// Space: O(N) to store the concatenated string (s + s).

class Solution {
public:
    bool rotateString(string s, string goal) {
        // Rotated strings must have equal length and goal must be a substring of (s + s)
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};

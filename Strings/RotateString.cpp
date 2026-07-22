// LC 796: Rotate String (Easy)
// Link: https://leetcode.com/problems/rotate-string/
// Approach: Modular arithmetic index matching. Check all starting positions where s[0] == goal[idx].
// Time: O(N^2) worst case where N is the length of string s.
// Space: O(1) auxiliary space.

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        int n = s.length();
        for (int idx = 0; idx < n; idx++) {
            // Check if current goal character matches the start of s
            if (goal[idx] == s[0]) {
                bool isMatch = true;
                for (int i = 0; i < n; i++) {
                    if (s[i] != goal[(i + idx) % n]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) return true;
            }
        }
        return false;
    }
};

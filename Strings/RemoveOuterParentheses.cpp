// LC 1021: Remove Outermost Parentheses (Easy)
// Link: https://leetcode.com/problems/remove-outermost-parentheses/
// Approach: Single-pass depth counter. Append '(' when depth > 0 before incrementing,
//           and append ')' when depth > 0 after decrementing.
// Time: O(N) where N is the length of string s.
// Space: O(1) auxiliary space (excluding the output string).

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                // If count > 0, it means this '(' is not an outermost parenthesis
                if (count > 0) {
                    ans += c;
                }
                count++;
            } else {
                count--;
                // If count > 0, it means this ')' is not an outermost parenthesis
                if (count > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};

// LC 1903: Largest Odd Number in String (Easy)
// Link: https://leetcode.com/problems/largest-odd-number-in-string/
// Approach: Backward linear scan to find the rightmost odd digit, then return the prefix substring.
// Time: O(N) where N is the length of string num.
// Space: O(1) auxiliary space (excluding substring result).

class Solution {
public:
    string largestOddNumber(string num) {
        // Iterate backwards from the end of the string
        for (int i = num.length() - 1; i >= 0; i--) {
            // Check if character is an odd digit
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

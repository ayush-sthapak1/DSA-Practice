// LeetCode 9: Palindrome Number
// Approach: Reverse the number and compare it with the original value
// Time Complexity: O(log10 n)  -> number of digits in the integer
// Space Complexity: O(1)       -> constant extra space

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes
        if (x < 0) return false;

        int original = x;
        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow before multiplying
            if (reversed > INT_MAX / 10 || 
               (reversed == INT_MAX / 10 && digit > 7)) {
                return false;
            }

            reversed = reversed * 10 + digit;
        }

        return reversed == original;
    }
};

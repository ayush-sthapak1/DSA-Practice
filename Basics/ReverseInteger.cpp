// LeetCode 7: Reverse Integer
// Approach: Extract digits using modulo and rebuild the number while checking for overflow
// Time Complexity: O(log10 n)  -> number of digits in the integer
// Space Complexity: O(1)       -> constant extra space

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;

            // Check for overflow before multiplying by 10
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }

            ans = ans * 10 + digit;
            x /= 10;
        }

        return ans;
    }
};

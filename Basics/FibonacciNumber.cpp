// LeetCode 509: Fibonacci Number
// Approach: Iterative dynamic programming using two variables
// Time Complexity: O(n)    -> loop runs n times
// Space Complexity: O(1)   -> constant extra space

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0, b = 1;

        for (int i = 2; i <= n; i++) {
            int next = a + b;
            a = b;
            b = next;
        }

        return b;
    }
};

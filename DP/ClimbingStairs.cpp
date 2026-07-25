// LC 70: Climbing Stairs (Easy)
// Link: https://leetcode.com/problems/climbing-stairs/
// Approach: Space-Optimized Dynamic Programming (Fibonacci pattern).
//           f(n) = f(n-1) + f(n-2) with base cases f(0) = 1, f(1) = 1.
// Time: O(N) where N is the number of steps.
// Space: O(1) auxiliary space.

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        int prev2 = 1; // Base case for f(0)
        int prev = 1;  // Base case for f(1)
        int curr = 0;

        for (int i = 2; i <= n; i++) {
            curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        
        return curr;
    }
};

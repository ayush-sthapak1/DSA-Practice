// LeetCode 69: Sqrt(x)
// Approach: Binary search on answer
// Time Complexity: O(log x)
// Space Complexity: O(1)

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;

        int low = 1, high = x - 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;

            if (val <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;  // floor(sqrt(x))
    }
};

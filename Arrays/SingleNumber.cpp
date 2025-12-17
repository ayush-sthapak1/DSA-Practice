// LeetCode 136: Single Number
// Approach: Use XOR to cancel out duplicate elements
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;   // XOR cancels duplicate numbers
        }

        return ans;
    }
};

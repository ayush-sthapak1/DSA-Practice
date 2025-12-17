// LeetCode 169: Majority Element
// Approach: Boyer–Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = 0;

        for (int num : nums) {
            if (count == 0) {
                element = num;
                count = 1;
            } else if (num == element) {
                count++;
            } else {
                count--;
            }
        }

        return element;
    }
};

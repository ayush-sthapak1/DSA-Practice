// LeetCode 1752: Check if Array Is Sorted and Rotated
// Approach: Traverse the array to detect a break in ascending order,
// then ensure the remaining elements follow sorted order
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        bool isascending = true;
        int i = 0;

        // First pass: check ascending order until a break is found
        for (; i < nums.size() - 1; i++) {
            if (nums[i] <= nums[i + 1])
                continue;
            else {
                i++;
                isascending = false;
                break;
            }
        }

        // Second pass: ensure remaining part is also sorted
        for (; i < nums.size() - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                isascending = true;
                continue;
            } else {
                isascending = false;
                break;
            }
        }

        return isascending;
    }
};

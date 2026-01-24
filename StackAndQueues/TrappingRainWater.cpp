// LeetCode 42: Trapping Rain Water
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                // left side is limiting
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];
                left++;
            } else {
                // right side is limiting
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }

        return ans;
    }
};

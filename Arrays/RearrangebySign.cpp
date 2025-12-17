// LeetCode 2149: Rearrange Array Elements by Sign
// Approach: Use an auxiliary array and place positives at even indices
// and negatives at odd indices
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int posIndex = 0; // even indices for positive numbers
        int negIndex = 1; // odd indices for negative numbers

        for (int num : nums) {
            if (num > 0) {
                ans[posIndex] = num;
                posIndex += 2;
            } else {
                ans[negIndex] = num;
                negIndex += 2;
            }
        }

        return ans;
    }
};

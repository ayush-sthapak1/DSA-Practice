// LeetCode 15: 3Sum
// Approach: Sort the array and use two pointers to find pairs for each fixed element
// Time Complexity: O(n^2)
// Space Complexity: O(1)  -> excluding the output array

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    // Skip duplicates for second and third numbers
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return ans;
    }
};

// LC 90: Subsets II
// Approach: Backtracking (Include/Exclude) with duplicate skipping
// Time: O(n * 2^n)  Space: O(n)

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int index) {
        if (index == (int)nums.size()) {
            result.push_back(curr);
            return;
        }

        // Case 1: Include nums[index]
        curr.push_back(nums[index]);
        solve(nums, result, curr, index + 1);
        curr.pop_back(); // Backtrack

        // Case 2: Exclude nums[index] (and all duplicates of it)
        int next = index + 1;
        while (next < (int)nums.size() && nums[index] == nums[next]) {
            next++;
        }
        solve(nums, result, curr, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        // Group duplicates together
        sort(nums.begin(), nums.end());
        solve(nums, result, curr, 0);
        return result;
    }
};

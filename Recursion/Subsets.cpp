// LC 78: Subsets
// Approach: Backtracking (Include/Exclude)
// Time: O(N * 2^N)  Space: O(N)

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int index) {
        // Base case: we've made a decision for every element
        if (index == (int)nums.size()) {
            result.push_back(curr);
            return;
        }

        // Case 1: Include nums[index]
        curr.push_back(nums[index]);
        solve(nums, result, curr, index + 1);
        curr.pop_back(); // Backtrack

        // Case 2: Exclude nums[index]
        solve(nums, result, curr, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(nums, result, curr, 0);
        return result;
    }
};

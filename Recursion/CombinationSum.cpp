// LC 39: Combination Sum
// Approach: Backtracking — reuse by staying at same index
// Time: O(2^(target/min)) Space: O(target/min)

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result,
               vector<int>& curr, int index, int currSum) {
        if (currSum == target) { result.push_back(curr); return; }
        if (index == (int)candidates.size() || currSum > target) return;

        // include candidates[index] — stay at same index (can reuse)
        curr.push_back(candidates[index]);
        solve(candidates, target, result, curr, index, currSum + candidates[index]);
        curr.pop_back();

        // skip candidates[index] — move forward
        solve(candidates, target, result, curr, index + 1, currSum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates, target, result, curr, 0, 0);
        return result;
    }
};

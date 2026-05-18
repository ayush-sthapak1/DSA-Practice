// LC 40: Combination Sum II
// Approach: Backtracking — no reuse + skip adjacent duplicates on skip branch
// Time: O(2^n)  Space: O(n)

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result,
               vector<int>& curr, int index, int currSum) {
        if (currSum == target) { result.push_back(curr); return; }
        if (index == (int)candidates.size() || currSum > target) return;

        // include candidates[index]
        curr.push_back(candidates[index]);
        solve(candidates, target, result, curr, index + 1, currSum + candidates[index]);
        curr.pop_back();

        // skip — jump over all duplicates of candidates[index]
        int next = index + 1;
        while (next < (int)candidates.size() && candidates[next] == candidates[index])
            next++;
        solve(candidates, target, result, curr, next, currSum);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, result, curr, 0, 0);
        return result;
    }
};

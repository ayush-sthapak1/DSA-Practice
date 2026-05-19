// LC 216: Combination Sum III
// Approach: Backtracking (Include/Exclude) with digit pool [1..9] and early stop
// Time: O(2^9) -> O(1)  Space: O(k)

class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& curr, int index, int currSum, int k, int n) {
        // Stop exploring when we reach the target size k
        if (curr.size() == k) {
            if (currSum == n) {
                result.push_back(curr);
            }
            return;
        }
        
        // Pruning and boundaries
        if (index > 9 || currSum > n) {
            return;
        }

        // Include current digit
        curr.push_back(index);
        solve(result, curr, index + 1, currSum + index, k, n);
        curr.pop_back(); // Backtrack

        // Skip current digit
        solve(result, curr, index + 1, currSum, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(result, curr, 1, 0, k, n);
        return result;
    }
};

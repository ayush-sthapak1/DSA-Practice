// GFG: Subsequence with Sum K
// Approach: Include/Exclude recursion with early exit
// Time: O(2^n)  Space: O(n)
// Note: curr > k pruning assumes non-negative array

class Solution {
public:
    bool solve(vector<int>& arr, int k, int idx, int curr) {
        if (curr == k) return true;                      // found valid subsequence
        if (idx == (int)arr.size() || curr > k) return false;

        // include arr[idx] OR skip it
        return solve(arr, k, idx + 1, curr + arr[idx]) || 
               solve(arr, k, idx + 1, curr);
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return solve(arr, k, 0, 0);
    }
};

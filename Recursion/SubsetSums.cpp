// GFG: Subset Sums
// Approach: Recursion (Include/Exclude) + sorting output
// Time: O(2^n log(2^n))  Space: O(n)

class Solution {
public:
    void solve(vector<int>& arr, vector<int>& sums, int index, int currSum) {
        // Base case: subset is complete
        if (index == (int)arr.size()) {
            sums.push_back(currSum);
            return;
        }
        
        // Include the current element
        solve(arr, sums, index + 1, currSum + arr[index]);
        
        // Exclude the current element
        solve(arr, sums, index + 1, currSum);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        solve(arr, sums, 0, 0);
        // Sort to meet GFG non-decreasing order requirement
        sort(sums.begin(), sums.end());
        return sums;
    }
};

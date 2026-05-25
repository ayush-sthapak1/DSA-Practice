// LC 139: Word Break (Medium)
// Approach: Top-Down 1D Dynamic Programming (Memoization)
// Time: O(N^2 * L)  Space: O(N + M * L)

class Solution {
public:
    bool solve(const string& s, const unordered_set<string>& wordSet, vector<int>& memo, int start) {
        // Base case: Entire string has been successfully segmented
        if (start == s.size()) {
            return true;
        }

        // Return cached result if already computed
        if (memo[start] != -1) {
            return memo[start];
        }

        int remainingLength = s.size() - start;

        // Try every possible prefix length starting at 'start'
        for (int i = 0; i < remainingLength; i++) {
            int len = i + 1;
            string prefix = s.substr(start, len);

            // If prefix exists in dictionary, check if the remaining suffix can be segmented
            if (wordSet.count(prefix)) {
                if (solve(s, wordSet, memo, start + len)) {
                    return memo[start] = 1; // Mark as segmentable and return
                }
            }
        }

        return memo[start] = 0; // Mark as unsegmentable
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);

        return solve(s, wordSet, memo, 0);
    }
};

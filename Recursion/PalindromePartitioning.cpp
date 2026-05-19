// LC 131: Palindrome Partitioning
// Approach: Backtracking (Prefix/Suffix cut loop) with Palindrome Pruning
// Time: O(N * 2^N)  Space: O(N)

class Solution {
public:
    // Helper to check if a substring is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(string& s, int start, vector<string>& curr, vector<vector<string>>& result) {
        // Base case: successfully partitioned the entire string
        if (start == (int)s.length()) {
            result.push_back(curr);
            return;
        }

        // Try cutting prefixes ending at index i
        for (int i = start; i < (int)s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                // Include the palindrome prefix
                curr.push_back(s.substr(start, i - start + 1));
                // Recurse on the remaining suffix
                solve(s, i + 1, curr, result);
                curr.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(s, 0, curr, result);
        return result;
    }
};

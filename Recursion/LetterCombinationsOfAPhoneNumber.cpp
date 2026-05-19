// LC 17: Letter Combinations of a Phone Number
// Approach: Backtracking (Multi-Branch Loop) with direct index mapping
// Time: O(3^N * 4^M)  Space: O(N + M)

class Solution {
public:
    void solve(string& digits, const vector<string>& mapping, vector<string>& result, int index, string& curr) {
        // Base case: formed a combination of target length
        if (index == (int)digits.size()) {
            result.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';
        const string& letters = mapping[digit];

        // Try all mapped letters for the current digit
        for (int i = 0; i < (int)letters.length(); i++) {
            curr.push_back(letters[i]);
            solve(digits, mapping, result, index + 1, curr);
            curr.pop_back(); // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        const vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string curr = "";

        // Passing curr by reference string& avoids copying it at every branch
        solve(digits, mapping, result, 0, curr);
        return result;
    }
};

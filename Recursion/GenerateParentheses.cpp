// LC 22: Generate Parentheses
// Approach: Backtracking with open/closed counters
// Time: O(4^n / √n)  Space: O(n)

class Solution {
public:
    void solve(int open, int closed, vector<string>& result, string curr) {
        if (open == 0 && closed == 0) {
            result.push_back(curr);
            return;
        }
        // place '(' only if budget remains
        if (open > 0)
            solve(open - 1, closed + 1, result, curr + '(');
        // place ')' only if there's an unmatched '('
        if (closed > 0)
            solve(open, closed - 1, result, curr + ')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, 0, result, "");
        return result;
    }
};

// GFG: All Possible Strings (Power Set / All Subsequences)
// Approach: Include/Exclude recursion at each index
// Time: O(n * 2^n)  Space: O(n)

class Solution {
public:
    void solve(string& s, int index, string curr, vector<string>& result) {
        if (index == (int)s.length()) {
            if (!curr.empty()) result.push_back(curr);
            return;
        }
        // include s[index]
        solve(s, index + 1, curr + s[index], result);
        // skip s[index]
        solve(s, index + 1, curr, result);
    }

    vector<string> AllPossibleStrings(string s) {
        vector<string> result;
        solve(s, 0, "", result);
        sort(result.begin(), result.end());
        return result;
    }
};

// LC 14: Longest Common Prefix (Easy)
// Link: https://leetcode.com/problems/longest-common-prefix/
// Approach: Horizontal scanning. Compare prefix sequentially with each string in the array.
// Time: O(S) where S is the total number of characters across all strings.
// Space: O(1) auxiliary space (excluding result substring).

class Solution {
public:
    string matchPrefix(string ans, string curr){
        int i = 0;
        while(i < ans.size() && i < curr.size()){
            if(ans[i] == curr[i]) i++;
            else break;
        }
        return curr.substr(0, i);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string ans = strs[0];
        for (const string& s : strs) {
            ans = matchPrefix(ans, s);
            if (ans.empty()) break; // Early exit if no common prefix remains
        }
        return ans;
    }
};

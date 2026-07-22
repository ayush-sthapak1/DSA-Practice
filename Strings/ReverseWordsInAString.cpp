// LC 151: Reverse Words in a String (Medium)
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Approach: In-Place Two-Pointer. 1) Reverse whole string, 2) Copy words and clean spaces, 3) Reverse individual words.
// Time: O(N) where N is the length of string s.
// Space: O(1) auxiliary space (modifies input string in-place).

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;

        while (i < n) {
            // Skip leading or consecutive spaces
            while (i < n && s[i] == ' ') i++;
            if (i == n) break;

            // Copy the current word to the 'right' index
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // Reverse the current word in-place to restore original word character order
            reverse(s.begin() + left, s.begin() + right);
            
            // Add a single space after the word
            s[right++] = ' ';
            left = right;
            i++;
        }

        // Resize string to strip the trailing space
        s.resize(right - 1);
        return s;
    }
};

// LC 242: Valid Anagram (Easy)
// Link: https://leetcode.com/problems/valid-anagram/
// Approach: Frequency array counting. Increment frequencies for string s and decrement for string t.
// Time: O(N) where N is the length of the strings.
// Space: O(1) auxiliary space (fixed-size array of size 26).

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> freq(26, 0);

        // Increment for s and decrement for t in a single pass
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        // If all character frequencies balance to 0, they are anagrams
        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
};

// LC 3: Longest Substring Without Repeating Characters (Medium)
// Approach: Optimal Sliding Window (Two-Pointer) with O(1) Hash Map Jump
// Time: O(N) single-pass
// Space: O(min(N, M)) where M is the character set size (e.g., 256 for extended ASCII)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        int n = s.length();
        
        // Map to store the last seen index of each character
        unordered_map<char, int> charMap;

        for (int right = 0; right < n; right++) {
            // If the character has been seen before, slide the left pointer
            // directly past its previous occurrence (only if it falls inside the current window)
            if (charMap.contains(s[right])) {
                left = max(left, charMap[s[right]] + 1);
            }

            // Update/record the character's latest index
            charMap[s[right]] = right;

            // Calculate the length of the current non-repeating substring
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

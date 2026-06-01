// LC 424: Longest Repeating Character Replacement (Medium)
// Approach: Optimal Sliding Window (Two-Pointer) with Frequency Array and Historical maxFreq
// Time: O(N) single-pass
// Space: O(1) auxiliary (size 26 frequency array)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int n = s.length();
        int maxFreq = 0;
        int maxLen = 0;
        
        // Frequency array for 26 uppercase English letters
        vector<int> freq(26, 0);

        for (int right = 0; right < n; right++) {
            // 1. Expand the window: count the new character at right
            freq[s[right] - 'A']++;
            
            // Update the historical maximum frequency in the window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // 2. Shrink the window: if replacements needed > k, slide left forward
            // No need to decrement maxFreq when shrinking left because we only care about
            // growing the window (which requires a larger local frequency than maxFreq).
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // 3. Now the window is guaranteed to be valid. Record maximum size.
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// GFG: Longest K unique characters substring (Medium)
// Approach: Optimal Sliding Window (Two-Pointer) with Frequency Counting and Exact K Tracker
// Time: O(N) single-pass
// Space: O(1) auxiliary (size 26 frequency array)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int left = 0;
        int n = s.size();
        int dist = 0; // Tracks the number of unique characters in the window
        int maxLen = -1;
        
        // Frequency array for 26 lowercase English letters
        vector<int> freq(26, 0);
        
        for (int right = 0; right < n; right++) {
            // 1. Expand the window: count character and update unique count
            if (freq[s[right] - 'a'] == 0) {
                dist++;
            }
            freq[s[right] - 'a']++;
            
            // 2. Shrink the window: if unique count exceeds k, slide left forward
            while (dist > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    dist--;
                }
                left++;
            }
            
            // 3. Record the maximum length ONLY when the window has exactly k unique characters
            if (dist == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
};

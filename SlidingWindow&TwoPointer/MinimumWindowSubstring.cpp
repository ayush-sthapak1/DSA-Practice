// LC 76: Minimum Window Substring (Hard)
// Approach: Optimal Sliding Window (Two-Pointer) with O(1) Match Counter (reqCount) and Index Tracking
// Time: O(N + M) single-pass
// Space: O(1) auxiliary (size 128 ASCII frequency array)

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        int m = s.size();
        int n = t.size();
        
        // Count frequencies of all characters in string t
        for (int i = 0; i < n; i++) {
            freq[t[i]]++;
        }

        int reqCount = n; // Total characters from t we still need to satisfy
        int left = 0;
        int minStart = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < m; right++) {
            // 1. Expand: If we actually need s[right], satisfy a requirement
            if (freq[s[right]] > 0) {
                reqCount--;
            }
            freq[s[right]]--;

            // 2. Shrink: While our window contains all required characters, make it smaller
            while (reqCount == 0) {
                // Record the minimum length and start index
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // Restore/eject the leftmost character
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    reqCount++; // Ejecting s[left] broke the requirements
                }
                left++;
            }
        }

        // Return empty string if no valid window was found
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

// LC 1358: Number of Substrings Containing All Three Characters (Medium)
// Approach: Optimal Sliding Window (Two-Pointer) with Left-Pointer Cumulative Counting
// Time: O(N) single-pass
// Space: O(1) auxiliary (size 3 frequency array)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int n = s.length();
        int result = 0;
        
        // Frequency array to count 'a', 'b', and 'c'
        vector<int> count(3, 0);

        for (int right = 0; right < n; right++) {
            // 1. Expand the window: include the new character
            count[s[right] - 'a']++;

            // 2. Shrink the window: if the window contains at least one of all three
            // slide left forward to find the first index that breaks validity.
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[left] - 'a']--;
                left++;
            }

            // 3. Every index from 0 up to left - 1 was a valid start position
            // ending at right. Therefore, there are exactly 'left' valid substrings.
            result += left;
        }

        return result;
    }
};

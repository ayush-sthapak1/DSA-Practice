// LC 727: Minimum Window Subsequence (Hard)
// Approach: Optimal Sliding Window (Two-Pointer Forward-Backward Match & Reset)
// Time: O(N * M) worst case, O(N) average case
// Space: O(1) auxiliary

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        int minStart = 0;
        int minLen = INT_MAX;
        
        int i = 0; // Pointer for s1
        int j = 0; // Pointer for s2
        
        while (i < n) {
            // Forward Pass: Match s2 in s1
            if (s1[i] == s2[j]) {
                j++;
                
                // If we have matched the entire subsequence s2
                if (j == m) {
                    int end = i;
                    j--; // Set j to the last index of s2
                    
                    // Backward Pass: Walk backward to find the optimal start position
                    while (end >= 0) {
                        if (s1[end] == s2[j]) {
                            j--;
                        }
                        if (j < 0) {
                            break;
                        }
                        end--;
                    }
                    
                    // 'end' is now the start of the minimum valid window ending at 'i'
                    int currentLen = i - end + 1;
                    if (currentLen < minLen) {
                        minLen = currentLen;
                        minStart = end;
                    }
                    
                    // Reset pointers: Start next search from the index after our start index
                    i = end + 1;
                    j = 0;
                    continue;
                }
            }
            i++;
        }
        
        return minLen == INT_MAX ? "" : s1.substr(minStart, minLen);
    }
};

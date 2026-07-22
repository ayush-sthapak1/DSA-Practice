// LC 1614: Maximum Nesting Depth of the Parentheses (Easy)
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Approach: Linear scan with depth counter. Increment on '(', decrement on ')', and track maximum depth.
// Time: O(N) where N is the length of string s.
// Space: O(1) auxiliary space.

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;

        for(char c : s){
            if(c == '('){
                count++;
                maxCount = max(maxCount, count); // Track maximum depth reached
            }
            else if(c == ')'){
                count--;
            }
        }
        return maxCount;
    }
};

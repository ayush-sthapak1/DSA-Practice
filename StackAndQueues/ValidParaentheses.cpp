// LeetCode 20: Valid Parentheses
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // handle closing brackets
            else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // check for matching pair
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        // stack must be empty at the end
        return st.empty();
    }
};

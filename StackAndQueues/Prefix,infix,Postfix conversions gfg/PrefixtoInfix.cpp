// Prefix to Infix Conversion
// Approach: Stack (scan from right to left)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string prefixToInfix(string s) {
        stack<string> st;

        // scan from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];

            // operand
            if (isalnum(c)) {
                st.push(string(1, c));
            }
            // operator
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string expr = "(" + op1 + c + op2 + ")";
                st.push(expr);
            }
        }

        return st.top();
    }
};

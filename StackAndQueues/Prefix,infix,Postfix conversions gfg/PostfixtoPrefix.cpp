// Postfix to Prefix Conversion
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string postfixToPrefix(string s) {
        stack<string> st;

        for (char c : s) {
            // operand
            if (isalnum(c)) {
                st.push(string(1, c));
            }
            // operator
            else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();

                string expr = c + op1 + op2;
                st.push(expr);
            }
        }

        return st.top();
    }
};

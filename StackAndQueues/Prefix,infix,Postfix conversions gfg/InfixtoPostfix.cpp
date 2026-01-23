// Infix to Postfix Conversion
// Handles operator precedence and associativity (^ is right associative)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string res = "";

        for (char c : s) {
            // Operand
            if (isalnum(c)) {
                res += c;
            }
            // Opening bracket
            else if (c == '(') {
                st.push(c);
            }
            // Closing bracket
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }
            // Operator
            else {
                while (!st.empty() &&
                      (precedence(st.top()) > precedence(c) ||
                      (precedence(st.top()) == precedence(c) && c != '^'))) {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

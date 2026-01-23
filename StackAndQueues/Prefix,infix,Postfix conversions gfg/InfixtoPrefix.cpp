// Infix to Prefix Conversion
// Handles precedence + reversed associativity correctly
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPrefix(string s) {
        // Step 1: Reverse infix
        reverse(s.begin(), s.end());

        // Step 2: Swap brackets
        for (char &c : s) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        stack<char> st;
        string res = "";

        // Step 3: Convert to postfix
        for (char c : s) {
            if (isalnum(c)) {
                res += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() &&
                      (precedence(st.top()) > precedence(c) ||
                      (precedence(st.top()) == precedence(c) && c == '^'))) {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix → prefix
        reverse(res.begin(), res.end());
        return res;
    }
};

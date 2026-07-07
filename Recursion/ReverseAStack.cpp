// GFG: Reverse a Stack
// Link: https://www.geeksforgeeks.org/problems/reverse-a-stack/1
// Approach: Recursion — Insert at Bottom
// Time: O(n²) | Space: O(n)

class Solution {
public:
    void insertAtBottom(stack<int> &st, int elem) {
        if (st.empty()) {
            st.push(elem);
            return;
        }
        int temp = st.top();
        st.pop();
        insertAtBottom(st, elem);
        st.push(temp);
    }

    void reverseStack(stack<int> &st) {
        if (st.empty()) return;
        int curr = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, curr);
    }
};

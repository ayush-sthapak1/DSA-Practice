// GFG: Sort a Stack
// Approach: Recursion — Sort then Insert
// Time: O(n²) | Space: O(n)

class Solution {
public:
    void sortedInsert(stack<int> &st, int elem) {
        if (st.empty() || elem >= st.top()) {
            st.push(elem);
            return;
        }
        int temp = st.top();
        st.pop();
        sortedInsert(st, elem);
        st.push(temp);
    }


    void sortStack(stack<int> &st) {
        if (st.empty()) return;
        int temp = st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st, temp);
    }
};
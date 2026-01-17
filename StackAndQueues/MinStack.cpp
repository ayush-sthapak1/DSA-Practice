// LeetCode 155: Min Stack
// Approach: Store {value, min_so_far} in stack
// Time Complexity: O(1) for all operations
// Space Complexity: O(n)

class MinStack {
    stack<pair<int,int>> st;   // {value, minimum till this element}

public:
    MinStack() {}

    void push(int val) {
        // compute minimum till current state
        int currMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currMin});
    }

    void pop() {
        // remove top element
        st.pop();
    }

    int top() {
        // return top value
        return st.top().first;
    }

    int getMin() {
        // minimum at current state
        return st.top().second;
    }
};

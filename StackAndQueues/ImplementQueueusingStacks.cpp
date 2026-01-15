// LeetCode 232: Implement Queue using Stacks
// Approach: Two Stacks (inStack & outStack)
// Time:
//   push -> O(1)
//   pop  -> amortized O(1)
//   peek -> amortized O(1)
// Space: O(n)

class MyQueue {
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {}

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

// LeetCode 225: Implement Stack using Queues
// Approach: Single Queue (Push-heavy)
// Time:
//   push -> O(n)
//   pop  -> O(1)
//   top  -> O(1)
// Space: O(n)

class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int size = q.size();

        // rotate previous elements behind x
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topVal = q.front();
        q.pop();
        return topVal;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

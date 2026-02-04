// LeetCode 901: Online Stock Span
// Approach: Monotonic Decreasing Stack
// Time Complexity: O(n) amortized
// Space Complexity: O(n)

class StockSpanner {
public:
    // stack stores {price, span}
    stack<pair<int,int>> st;

    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // absorb spans of smaller or equal prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

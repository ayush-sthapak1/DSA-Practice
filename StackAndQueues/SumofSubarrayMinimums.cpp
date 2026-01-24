// LeetCode 907: Sum of Subarray Minimums
// Approach: Monotonic Stack + Contribution Counting
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // Next Smaller or Equal Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (long long)arr[i] * left[i] * right[i];
            ans = (ans + contrib) % MOD;
        }

        return ans;
    }
};

// LeetCode 2104: Sum of Subarray Ranges
// Approach: Monotonic Stack + Contribution Technique
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> left(n), right(n);
        stack<int> st;

        // ---------- MAX CONTRIBUTION ----------

        // Previous Greater (strict)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            ans += (long long) nums[i] * left[i] * right[i];
        }

        // clear stack
        while (!st.empty()) st.pop();

        // ---------- MIN CONTRIBUTION ----------

        // Previous Smaller (strict)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            ans -= (long long) nums[i] * left[i] * right[i];
        }

        return ans;
    }
};

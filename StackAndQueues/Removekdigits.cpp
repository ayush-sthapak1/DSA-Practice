// LeetCode 402: Remove K Digits
// Approach: Greedy + Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";

        for (char c : num) {
            // remove previous bigger digits
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }

            // avoid leading zeros
            if (!st.empty() || c != '0') {
                st.push(c);
            }
        }

        // remove remaining digits from end
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // build result
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};

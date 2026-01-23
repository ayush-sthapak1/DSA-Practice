// LeetCode 503: Next Greater Element II
// Approach: Monotonic Decreasing Stack + Circular Traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores potential next greater elements

        // traverse array twice (circular behavior)
        for (int i = 2 * n - 1; i >= 0; i--) {

            // remove elements smaller than or equal to current
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // fill answer only during first pass
            if (i < n) {
                if (!st.empty())
                    ans[i] = st.top();
            }

            // push current element
            st.push(nums[i % n]);
        }

        return ans;
    }
};

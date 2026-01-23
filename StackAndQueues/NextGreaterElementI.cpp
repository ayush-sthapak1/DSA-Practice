// LeetCode 496: Next Greater Element I
// Approach: Monotonic Decreasing Stack (Right to Left)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;

        // traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // remove elements smaller than or equal to current
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // top of stack is next greater element
            if (!st.empty())
                mp[nums2[i]] = st.top();
            else
                mp[nums2[i]] = -1;

            // push current element
            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};

// LeetCode 735: Asteroid Collision
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // collision only when left > 0 and right < 0
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (st.top() < -a) {
                    st.pop();           // top explodes
                    continue;
                } else if (st.top() == -a) {
                    st.pop();           // both explode
                }
                destroyed = true;       // current explodes
                break;
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

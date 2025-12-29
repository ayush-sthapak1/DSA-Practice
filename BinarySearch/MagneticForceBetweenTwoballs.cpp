// LeetCode 1552: Magnetic Force Between Two Balls
// Approach: Binary search on minimum distance (maximize)
// Time Complexity: O(n log(maxDistance))
// Space Complexity: O(1)

class Solution {
public:
    bool check(vector<int>& position, int m, int dist) {
        int count = 1;                 // place first ball
        int lastPos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= dist) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();

        int low = 1;
        int high = position[n - 1] - position[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(position, m, mid)) {
                ans = mid;
                low = mid + 1;     // try larger minimum distance
            } else {
                high = mid - 1;    // distance too large
            }
        }
        return ans;
    }
};

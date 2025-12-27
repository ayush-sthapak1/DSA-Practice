// LeetCode 1482: Minimum Number of Days to Make m Bouquets
// Approach: Binary search on days
// Time Complexity: O(n log maxDay)
// Space Complexity: O(1)

class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                bouquets += count / k;
                count = 0;
            }
        }
        bouquets += count / k;   // last segment
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int x : bloomDay) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        int low = mini, high = maxi;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

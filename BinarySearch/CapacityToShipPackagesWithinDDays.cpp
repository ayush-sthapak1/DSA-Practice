// LeetCode 1011: Capacity To Ship Packages Within D Days
// Approach: Binary search on shipping capacity
// Time Complexity: O(n log sum(weights))
// Space Complexity: O(1)

class Solution {
public:
    bool check(vector<int>& weights, int days, int cap) {
        int daysUsed = 1;
        int currCap = cap;

        for (int w : weights) {
            if (w > cap) return false;

            if (currCap >= w) {
                currCap -= w;
            } else {
                daysUsed++;
                currCap = cap - w;
            }
        }
        return daysUsed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(weights, days, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller capacity
            } else {
                low = mid + 1;    // capacity too small
            }
        }
        return ans;
    }
};

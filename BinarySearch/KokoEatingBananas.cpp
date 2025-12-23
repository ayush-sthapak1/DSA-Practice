// LeetCode 875: Koko Eating Bananas
// Approach: Binary search on eating speed
// Time Complexity: O(n log max(piles))
// Space Complexity: O(1)

class Solution {
public:
    int maxElem(vector<int>& piles) {
        int mx = 0;
        for (int x : piles)
            mx = max(mx, x);
        return mx;
    }

    int calcHours(vector<int>& piles, int k) {
        int hours = 0;
        for (int x : piles) {
            hours += (x + k - 1) / k;   // ceil(x / k)
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int high = maxElem(piles);
        if (high == 0) return 0;

        int low = 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int hours = calcHours(piles, mid);

            if (hours <= h) {
                high = mid;      // valid speed, try smaller
            } else {
                low = mid + 1;   // too slow
            }
        }
        return low;
    }
};

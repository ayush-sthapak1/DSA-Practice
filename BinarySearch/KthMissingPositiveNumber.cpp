// LeetCode 1539: Kth Missing Positive Number
// Approach: Binary search using missing count formula
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // low is the number of elements before the kth missing number
        return low + k;
    }
};

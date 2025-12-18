// LeetCode 493: Reverse Pairs
// Approach: Modified merge sort to count reverse pairs during merge
// Condition: nums[i] > 2 * nums[j], i < j
// Time Complexity: O(n log n)
// Space Complexity: O(log n)

class Solution {
public:
    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        int count = mergeSort(nums, l, mid)
                  + mergeSort(nums, mid + 1, r);

        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        inplace_merge(nums.begin() + l,
                      nums.begin() + mid + 1,
                      nums.begin() + r + 1);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

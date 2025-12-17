// LeetCode 560: Subarray Sum Equals K
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;

        // Base case: prefix sum = 0 occurs once
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Check if there exists a prefix sum such that
            // current_sum - prefix_sum = k
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store/update the current prefix sum
            mp[sum]++;
        }

        return count;
    }
};

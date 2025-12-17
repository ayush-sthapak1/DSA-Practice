// LeetCode 229: Majority Element II
// Approach: Extended Boyer–Moore Voting Algorithm
// At most two elements can appear more than ⌊n/3⌋ times
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cand1 = 0, cand2 = 1;   // initialize to different values
        int count1 = 0, count2 = 0;
        int n = nums.size();

        // First pass: find potential candidates
        for (int x : nums) {
            if (x == cand1) count1++;
            else if (x == cand2) count2++;
            else if (count1 == 0) {
                cand1 = x;
                count1 = 1;
            }
            else if (count2 == 0) {
                cand2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Second pass: verify the candidates
        count1 = 0;
        count2 = 0;
        for (int x : nums) {
            if (x == cand1) count1++;
            else if (x == cand2) count2++;
        }

        if (count1 > n / 3) ans.push_back(cand1);
        if (count2 > n / 3) ans.push_back(cand2);

        return ans;
    }
};

// LC 904: Fruit Into Baskets (Medium)
// Approach: Optimal Sliding Window (Two-Pointer) with Frequency Hash Map
// Time: O(N) single-pass
// Space: O(1) auxiliary (map stores at most 3 distinct keys)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitCount;
        int left = 0;
        int maxLen = 0;
        int n = fruits.size();

        for (int right = 0; right < n; right++) {
            // 1. Expand the window: include current fruit
            fruitCount[fruits[right]]++;

            // 2. Shrink the window: if we exceed 2 distinct types, slide left forward
            while (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                
                // If frequency becomes 0, remove the fruit type from the map
                if (fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]);
                }
                
                left++;
            }

            // 3. Now the window is guaranteed to be valid. Record maximum size.
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

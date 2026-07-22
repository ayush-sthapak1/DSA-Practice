// LC 451: Sort Characters By Frequency (Medium)
// Link: https://leetcode.com/problems/sort-characters-by-frequency/
// Approach: Frequency map + Max-Heap (Priority Queue). Count character frequencies,
//           push {freq, char} pairs to max-heap, and build the answer string.
// Time: O(N + K log K) where N is string length and K is number of unique characters (K <= 128).
// Space: O(N) to store frequency map and answer string.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        // Max-Priority Queue storing {frequency, character}
        priority_queue<pair<int, char>> pq;

        // Count frequency of each character
        for (char c : s) {
            mp[c]++;
        }
        
        // Push frequencies into max-heap to sort by frequency descending
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (!pq.empty()) {
            auto topElement = pq.top();
            pq.pop();

            int freq = topElement.first;
            char ch = topElement.second;

            // Append character 'freq' times
            ans.append(freq, ch);
        }

        return ans;
    }
};

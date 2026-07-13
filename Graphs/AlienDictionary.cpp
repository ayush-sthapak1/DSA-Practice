// GFG / LC 269: Alien Dictionary (Hard)
// Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
// Approach: Build dependency graph of characters by comparing adjacent words.
//           Use BFS Topological Sort (Kahn's Algorithm) to find character order.
// Time: O(N * L + K) where N is number of words, L is max word length, K is unique characters.
// Space: O(K + U) where K is number of alphabets (26) and U is relations.

class Solution {
public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> inDegree(26, -1); // -1 means character is not present in dictionary
        
        // Identify all unique characters present in the dictionary
        int uniqueCharCount = 0;
        for (const string& word : words) {
            for (char ch : word) {
                if (inDegree[ch - 'a'] == -1) {
                    inDegree[ch - 'a'] = 0;
                    uniqueCharCount++;
                }
            }
        }
        
        // Build adjacency list by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            
            bool hasDiffered = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';
                    
                    adj[u].push_back(v);
                    inDegree[v]++;
                    hasDiffered = true;
                    break;
                }
            }
            
            // Edge case: if w1 is a prefix of w2 and w1 is longer (e.g., "apple", "app"), it's invalid
            if (!hasDiffered && w1.length() > w2.length()) {
                return "";
            }
        }
        
        // Enqueue all characters that have 0 in-degree (no prerequisites)
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        string result = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            result += (char)(node + 'a');
            
            // Decrement in-degree for neighbors
            for (int nbr : adj[node]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        // If result does not contain all unique characters, a cycle exists
        if (result.length() != uniqueCharCount) {
            return "";
        }
        
        return result;
    }
};

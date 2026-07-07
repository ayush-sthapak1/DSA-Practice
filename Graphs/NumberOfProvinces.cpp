// LC 547: Number of Provinces (Medium)
// Link: https://leetcode.com/problems/number-of-provinces/
// Approach: DFS connected components traversal on adjacency matrix.
//           Uses vector<bool> for bit-level space optimization.
// Time: O(V^2) where V is the number of vertices (since we parse a V x V matrix).
// Space: O(V) auxiliary space for visited array and recursion stack.

class Solution {
public:
    void dfs(int v, vector<bool> &visited, vector<vector<int>> &isConnected) {
        visited[v] = true;
        
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[v][i] == 1 && !visited[i]) {
                dfs(i, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, isConnected);
            }
        }
        return count;
    }
};

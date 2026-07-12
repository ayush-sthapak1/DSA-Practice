// GFG: DFS Traversal of Graph (Easy)
// Link: https://www.geeksforgeeks.org/problems/dfs-traversal-of-graph/1
// Approach: Recursive Depth-First Search (DFS) starting from node 0.
// Time: O(V + E) where V is the number of vertices and E is the number of edges.
// Space: O(V) auxiliary space for visited array and recursion stack.

class Solution {
  private:
    void dfsHelper(int v, vector<int> &visited, vector<vector<int>> &adj, vector<int> &result) {
        visited[v] = 1;
        result.push_back(v); // Collect node in traversal order
        
        // Recurse for all unvisited neighbors
        for (int nbr : adj[v]) {
            if (!visited[nbr]) {
                dfsHelper(nbr, visited, adj, result);
            }
        }
    }

  public:
    vector<int> dfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> result;
        
        dfsHelper(0, visited, adj, result); // Start DFS from node 0
        return result;
    }
};

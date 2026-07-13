// GFG: Topological Sort (Medium)
// Link: https://www.geeksforgeeks.org/problems/topological-sort/1
// Approach: DFS based topological sort. Pushes node to result after all its
//           descendants are visited, then reverses the result.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V + E) to build adjacency list, and O(V) for visited array/recursion stack.

class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& result, int node) {
        vis[node] = true;
        
        // Recurse for all unvisited neighbors/descendants
        for(int nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(adj, vis, result, nbr);
            }
        }
        // Push node to result after all its descendants are finished
        result.push_back(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Build adjacency list internally from edges list
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        vector<int> result;
        
        // Traverse all components to handle disconnected graphs
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(adj, vis, result, i);
            }
        }
        
        // Reverse result since ancestors must appear before descendants
        reverse(result.begin(), result.end());
        return result;
    }
};

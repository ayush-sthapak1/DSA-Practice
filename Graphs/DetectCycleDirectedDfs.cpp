// GFG: Cycle Detection in a Directed Graph (Medium)
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Approach: DFS recursion stack tracking using pathVis.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V) auxiliary space for recursion stack and visited arrays.

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = true;
        pathVis[node] = true; // Mark as part of current recursion path
        
        for(int nbr : adj[node]) {
            if(!vis[nbr]) {
                if(dfs(nbr, adj, vis, pathVis)) return true;
            }
            // If the neighbor is already visited in the CURRENT path, we found a cycle
            else if(pathVis[nbr]) {
                return true;
            }
        }
        
        pathVis[node] = false; // Backtrack (remove from current path)
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        // Build the adjacency list from edges list
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);

        // Check all components to handle disconnected graphs
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

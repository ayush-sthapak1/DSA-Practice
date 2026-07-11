// GFG: Detect cycle in an undirected graph (Medium)
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Approach: BFS cycle detection using parent pointer tracking.
//           Works for disconnected components by checking all vertices.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V + E) to build the adjacency list and O(V) for visited array/queue.

class Solution {
public:
    bool detectCycle(int src, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    q.push({nbr, node});
                }
                else if (parent != nbr) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detectCycle(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};

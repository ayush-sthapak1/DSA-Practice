// LC 1192: Critical Connections in a Network (Hard)
// Link: https://leetcode.com/problems/critical-connections-in-a-network/
// Approach: Tarjan's Algorithm using DFS with discovery time disc[] and lowest reachable time low[].
//           An edge (u, v) is a bridge if low[v] > disc[u].
// Time: O(V + E) where V is n and E is the number of connections (single DFS pass).
// Space: O(V + E) for discovery arrays, low arrays, recursion stack, and adjacency list.

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<bool>& visited, vector<int>& disc, 
             vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& bridges) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Ignore direct edge back to DFS parent

            if (!visited[neighbor]) {
                dfs(neighbor, node, visited, disc, low, adj, bridges);
                
                // On return from DFS, update lowest reachable time of current node
                low[node] = min(low[node], low[neighbor]);

                // Bridge Condition: neighbor subtree cannot reach node or any ancestor of node
                if (low[neighbor] > disc[node]) {
                    bridges.push_back({node, neighbor});
                }
            } else {
                // Back-edge encountered: update low value using neighbor's discovery time
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build undirected adjacency list from edge connections
        vector<vector<int>> adj(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<bool> visited(n, false);
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> bridges;

        // The graph is connected as per problem constraints, so starting DFS from 0 suffices
        dfs(0, -1, visited, disc, low, adj, bridges);

        return bridges;
    }
};

// GFG: Bridge Edge in a Graph (Medium)
// Link: https://www.geeksforgeeks.org/problems/bridge-edge-in-a-graph/1
// Approach: Edge removal + BFS connectivity check. Ignore edge (c, d) when building graph,
//           then run BFS from c. If d is reachable, (c, d) is NOT a bridge; otherwise it IS.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V + E) for adjacency list, visited array, and BFS queue.

class Solution {
public:
    // Function to check if edge (c, d) is a bridge
    bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
        // Step 1: Build the Adjacency List IGNORING the edge (c, d)
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Ignore edge between c and d in both directions
            if ((u == c && v == d) || (u == d && v == c)) {
                continue;
            }
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Run BFS starting from node 'c' to see if 'd' is still reachable
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(c);
        visited[c] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // If we managed to reach 'd' without using edge (c, d), it's NOT a bridge
            if (curr == d) return false;

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // If node 'd' is unreachable, (c, d) is a bridge
        return true;
    }
};

// GFG: Articulation Point - I (Hard)
// Link: https://www.geeksforgeeks.org/problems/articulation-point-1/1
// Approach: Tarjan's Algorithm using DFS with discovery time disc[] and lowest reachable time low[].
//           Non-root node u is an articulation point if low[v] >= disc[u] for some neighbor v.
//           Root node (parent == -1) is an articulation point if it has > 1 child in the DFS tree.
// Time: O(V + E) where V is vertices and E is edges (single DFS pass).
// Space: O(V + E) for discovery arrays, low arrays, recursion stack, and adjacency list.

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<bool>& visited, vector<int>& disc, 
             vector<int>& low, vector<bool>& isCutPoint, vector<vector<int>>& adj) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int children = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Ignore direct edge back to DFS parent

            if (!visited[neighbor]) {
                children++;
                dfs(neighbor, node, visited, disc, low, isCutPoint, adj);

                // Update low of current node after exploring neighbor subtree
                low[node] = min(low[node], low[neighbor]);

                // Condition 1: Non-root node check
                if (parent != -1 && low[neighbor] >= disc[node]) {
                    isCutPoint[node] = true;
                }
            } else {
                // Back-edge found: update low value using neighbor's discovery time
                low[node] = min(low[node], disc[neighbor]);
            }
        }

        // Condition 2: Root node check (more than 1 child in DFS tree)
        if (parent == -1 && children > 1) {
            isCutPoint[node] = true;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> isCutPoint(V, false);

        // Step 2: Handle disconnected graphs by calling DFS for every unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, disc, low, isCutPoint, adj);
            }
        }

        // Step 3: Collect result nodes
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (isCutPoint[i]) {
                ans.push_back(i);
            }
        }

        // Step 4: Return {-1} if no articulation point exists
        if (ans.empty()) return {-1};

        return ans;
    }
};

// GFG: Connected Components in an Undirected Graph (Easy/Medium)
// Link: https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
// Approach: Construct adjacency list and perform DFS connectivity traversal.
// Time: O(V + E) where V is the number of vertices and E is the number of edges.
// Space: O(V + E) auxiliary space to store the adjacency list, visited array, and recursion stack.

class Solution {
private:
    void dfs(int v, vector<bool> &visited, const vector<vector<int>> &adj, vector<int> &comp) {
        visited[v] = true;
        comp.push_back(v); // Collect node in current component
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, comp);
            }
        }
    }
    
public:
    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges) {
        // Build bidirectional adjacency list
        vector<vector<int>> adj(V);
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        vector<vector<int>> result;

        // Traverse all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> comp;
                dfs(i, visited, adj, comp);
                result.push_back(comp);
            }
        }
        return result;
    }
};

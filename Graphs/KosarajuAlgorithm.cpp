// GFG: Strongly Connected Components - Kosaraju's Algorithm (Medium/Hard)
// Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Approach: 3-step Kosaraju's Algorithm:
//           1) DFS to order nodes by finishing time (Stack).
//           2) Transpose/Reverse all directed edges of the graph.
//           3) DFS on reversed graph in order of stack pops to count SCCs.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V + E) to store reversed graph, stack, and visited array.

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        
        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, st);
            }
        }
        
        // Push to stack after visiting all reachable descendants (finishing time order)
        st.push(node);
    }
    
    void dfsForRev(int node, vector<vector<int>>& adjRev, vector<bool>& vis) {
        vis[node] = true;
        
        for (int nbr : adjRev[node]) {
            if (!vis[nbr]) {
                dfsForRev(nbr, adjRev, vis);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>>& edges) {
        // Step 1: Build original adjacency list and get finishing time stack
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        
        // Step 2: Transpose / Reverse the graph edges
        vector<vector<int>> adjRev(V);
        for (int i = 0; i < V; i++) {
            vis[i] = false; // Reset visited array for second DFS
            for (int node : adj[i]) {
                adjRev[node].push_back(i); // Reverse u -> v to v -> u
            }
        }
        
        // Step 3: Run DFS on reversed graph in stack order
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (!vis[node]) {
                dfsForRev(node, adjRev, vis);
                scc++; // Increment SCC count for each unvisited component
            }
        }
        
        return scc;
    }
};

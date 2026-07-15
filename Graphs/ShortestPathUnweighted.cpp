// GFG: Shortest Path in Undirected Graph with Unit Distance (Easy/Medium)
// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Approach: Breadth-First Search (BFS) to find shortest path in unweighted graph.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V + E) to build adjacency list, and O(V) for visited array/queue.

class Solution {
public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Build adjacency list internally
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(V, false);
        vis[src] = true; // Mark source as visited immediately
        
        // Queue stores {node, distance}
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            // Return distance immediately when destination is reached
            if(node == dest) return dist;
            
            for(int nbr : adj[node]){
                if(!vis[nbr]){
                    q.push({nbr, dist + 1});
                    vis[nbr] = true; // Mark as visited immediately when pushing
                }
            }
        }
        return -1; // Unreachable
    }
};

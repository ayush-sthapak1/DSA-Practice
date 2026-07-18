// GFG: Minimum Spanning Tree - Prim's Algorithm (Medium)
// Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Approach: Prim's Algorithm using a Min-Priority Queue to greedily construct the MST.
// Time: O(E * log V) where V is vertices and E is edges.
// Space: O(V + E) to build adjacency list, and O(V) for visited array/priority queue.

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Build adjacency list internally
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<bool> vis(V, false);
        // Min-Priority Queue storing {edge_weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Start from node 0 with edge weight 0
        pq.push({0, 0});
        
        int minSum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Skip if the node is already part of the MST
            if(vis[node]) continue;
            
            // Add node to MST
            vis[node] = true;
            minSum += wt;
            
            for(auto nbr : adj[node]){
                int nbrNode = nbr.first;
                int nbrWt = nbr.second;
                
                // If neighbor is not in MST, push to the queue
                if(!vis[nbrNode]){
                    pq.push({nbrWt, nbrNode});
                }
            }
        }
        
        return minSum;
    }
};

// GFG: Dijkstra Algorithm (Medium)
// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Approach: Dijkstra's Algorithm using Min-Priority Queue (Min-Heap).
// Time: O(E * log V) where V is vertices and E is edges.
// Space: O(V + E) to build adjacency list, and O(V) for distance array/queue.

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list internally
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Min-Priority Queue storing {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distArray(V, INT_MAX);
        
        pq.push({0, src});
        distArray[src] = 0;
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Skip processing if a shorter path to this node has already been found
            if(dist > distArray[node]) continue;
            
            for(auto nbr : adj[node]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;
                
                // Relaxation step
                if(dist + nbrDist < distArray[nbrNode]){
                    distArray[nbrNode] = dist + nbrDist;
                    pq.push({dist + nbrDist, nbrNode});
                }
            }
        }
        return distArray;
    }
};

// GFG: Distance from the Source (Bellman-Ford Algorithm) (Medium)
// Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Approach: Bellman-Ford Algorithm. Relax all edges V - 1 times, 
//           then check for negative weight cycles on the V-th iteration.
// Time: O(V * E) where V is vertices and E is edges.
// Space: O(V) auxiliary space for distance array.

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Initialize distances with 1e8 (standard infinity value to prevent addition overflow)
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        // Relax all edges V - 1 times
        for(int i = 0; i < V - 1; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // 1 more relaxation step to detect negative weight cycles
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2]; 
            
            if(dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1}; // Negative weight cycle detected
            }
        }
        
        return dist;
    }
};

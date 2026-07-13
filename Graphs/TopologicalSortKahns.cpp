// GFG: Topological Sort - Kahn's Algorithm (Medium)
// Link: https://www.geeksforgeeks.org/problems/topological-sort/1
// Approach: BFS based topological sort (Kahn's Algorithm) using in-degrees.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V + E) to build adjacency list, and O(V) for queue/in-degrees array.

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> inDegree(V, 0);
        
        // Build adjacency list and calculate in-degrees
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // Push all nodes with 0 in-degree to the queue
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> result;
        
        // BFS traversal
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            // Decrement in-degree for neighbors and push if it becomes 0
            for(int nbr : adj[node]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return result;
    }
};

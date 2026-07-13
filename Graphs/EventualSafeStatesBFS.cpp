// LC 802: Find Eventual Safe States - BFS (Medium)
// Link: https://leetcode.com/problems/find-eventual-safe-states/
// Approach: BFS (Kahn's Algorithm) on reversed graph. 
//           Reversing edges turns terminal nodes (out-degree 0) into source nodes (in-degree 0).
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V + E) for reversed adjacency list and O(V) for queue/in-degrees.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);

        // Build reversed adjacency list and calculate original out-degrees (reversed in-degrees)
        for(int i = 0; i < V; i++){
            for(int it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        
        // Enqueue all terminal nodes (nodes with 0 out-degree in original graph)
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
                safeNodes.push_back(i);
            }
        }

        // BFS traversal
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nbr : adjRev[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                    safeNodes.push_back(nbr);
                }
            }
        }
        
        // Sort final safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

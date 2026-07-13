// LC 785: Is Graph Bipartite? (Medium)
// Link: https://leetcode.com/problems/is-graph-bipartite/
// Approach: BFS 2-coloring. If adjacent nodes have same color, graph is not bipartite.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V) for visited/color array and queue.

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1); // -1: uncolored, 0: color A, 1: color B
        
        // Loop to handle disconnected components
        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 1; // Assign initial color

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int nbr : graph[node]){
                        if(color[nbr] == -1){
                            color[nbr] = 1 - color[node]; // Toggle color (0 <-> 1)
                            q.push(nbr);
                        }
                        else if(color[nbr] == color[node]){
                            return false; // Found adjacent nodes with same color
                        }
                    }
                }
            }
        }
        return true;
    }
};

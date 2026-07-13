// LC 802: Find Eventual Safe States (Medium)
// Link: https://leetcode.com/problems/find-eventual-safe-states/
// Approach: DFS cycle detection using vis, pathVis, and a safe array.
// Time: O(V + E) where V is vertices and E is edges.
// Space: O(V) auxiliary space for visited, pathVis, and recursion stack.

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& pathVis, vector<int>& safe, int node) {
        vis[node] = true;
        pathVis[node] = true;

        for(int nbr : graph[node]) {
            if(!vis[nbr]) {
                if(dfs(graph, vis, pathVis, safe, nbr)) {
                    return true; // Unsafe path detected
                }
            }
            // If neighbor is currently in the active path, or was previously found to be unsafe
            else if(pathVis[nbr] || safe[nbr] == 0) {
                return true; 
            }
        }
        
        safe[node] = 1; // Mark current node as safe
        pathVis[node] = false; // Backtrack
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        vector<int> safe(V, 0); // 0: unsafe/unprocessed, 1: safe

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(graph, vis, pathVis, safe, i);
            }
        }

        vector<int> result;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};

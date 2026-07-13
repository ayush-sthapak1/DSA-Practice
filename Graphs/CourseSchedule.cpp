// LC 207: Course Schedule (Medium)
// Link: https://leetcode.com/problems/course-schedule/
// Approach: DFS directed cycle detection using global vis and pathVis recursion stack trackers.
// Time: O(V + E) where V is numCourses and E is prerequisites.
// Space: O(V + E) to build adjacency list, and O(V) for visited arrays.

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis, int node) {
        pathVis[node] = true;
        vis[node] = true;
        
        for(int nbr : adj[node]) {
            if(!vis[nbr]) {
                if(dfs(adj, vis, pathVis, nbr)) return true;
            }
            // If the neighbor is already in the current recursion path, a cycle exists
            else if(pathVis[nbr]) {
                return true;
            }
        }
        
        pathVis[node] = false; // Backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        // Check each component for cycles
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(adj, vis, pathVis, i)) return false; // Cycle detected: cannot finish
            }
        }
        return true;
    }
};

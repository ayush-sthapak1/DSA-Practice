// LC 210: Course Schedule II (Medium)
// Link: https://leetcode.com/problems/course-schedule-ii/
// Approach: DFS Topological Sort with cycle detection (using vis and pathVis).
// Time: O(V + E) where V is numCourses and E is prerequisites.
// Space: O(V + E) to build adjacency list, and O(V) for visited arrays/recursion stack.

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis, vector<int>& result, int node) {
        pathVis[node] = true;
        vis[node] = true;

        for(int nbr : adj[node]) {
            if(!vis[nbr]) {
                if(dfs(adj, vis, pathVis, result, nbr)) {
                    return true;
                }
            }
            // If neighbor is visited and in the current recursion stack, a cycle is found
            else if(pathVis[nbr]) {
                return true;
            }
        }

        result.push_back(node); // Push to result after processing descendants
        pathVis[node] = false; // Backtrack
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list (bi -> ai dependency)
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        vector<int> result;

        // Traverse all courses
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(adj, vis, pathVis, result, i)) {
                    return {}; // Cycle detected: impossible to finish all courses
                }
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

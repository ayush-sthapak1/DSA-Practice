// LC 210: Course Schedule II (Medium)
// Link: https://leetcode.com/problems/course-schedule-ii/
// Approach: BFS Topological Sort (Kahn's Algorithm) using in-degrees.
// Time: O(V + E) where V is numCourses and E is prerequisites.
// Space: O(V + E) to build adjacency list, and O(V) for queue/in-degrees array.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build adjacency list and calculate in-degrees
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Push all nodes with 0 dependencies to the queue
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = numCourses;
        vector<int> result;
        
        // BFS traversal
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
            count--;
            result.push_back(node);
        }
        
        // If count is not 0, a cycle exists (not all courses could be processed)
        if(count > 0) return {};
        return result;
    }
};

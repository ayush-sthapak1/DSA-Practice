// GFG: BFS Traversal of Graph (Easy)
// Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Approach: Queue-based level-order traversal starting from node 0.
// Time: O(V + E) where V is the number of vertices and E is the number of edges.
// Space: O(V) auxiliary space for visited array and queue.

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        queue<int> q;
        
        // Start traversal from node 0
        q.push(0);
        visited[0] = 1;
        vector<int> result;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            // Traverse all unvisited neighbors
            for (int i = 0; i < edges[curr].size(); i++) {
                int nbr = edges[curr][i];
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
        return result;
    }
};

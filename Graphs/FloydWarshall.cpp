// GFG: Floyd Warshall (Medium)
// Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Approach: Floyd-Warshall multi-source shortest path algorithm using 3 nested loops.
// Time: O(n^3) where n is number of vertices.
// Space: O(1) auxiliary space as we modify the distance matrix in-place.

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        // k is the intermediate vertex
        for (int k = 0; k < n; k++) {
            // i is the source vertex
            for (int i = 0; i < n; i++) {
                // j is the destination vertex
                for (int j = 0; j < n; j++) {
                    // Check if path exists via vertex k
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};

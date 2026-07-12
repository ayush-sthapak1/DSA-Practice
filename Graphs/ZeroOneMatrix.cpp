// LC 542: 01 Matrix (Medium)
// Link: https://leetcode.com/problems/01-matrix/
// Approach: Multi-source BFS starting from all 0s.
//           Optimized queue structure by retrieving distance from result matrix.
// Time: O(n * m) where n and m are matrix dimensions.
// Space: O(n * m) in the worst case for queue.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> result(n, vector<int>(m, -1));

        // Queue stores coordinate pairs {row, col}
        queue<pair<int,int>> q;

        // Enqueue all 0s and initialize their distances to 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;

            // Check all 4 cardinal neighbors
            for(int d = 0; d < 4; d++) {
                int ni = i + dRow[d];
                int nj = j + dCol[d];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && result[ni][nj] == -1) {
                    result[ni][nj] = result[i][j] + 1; // Retrieve distance from parent
                    q.push({ni, nj});
                }
            }
        }

        return result;
    }
};

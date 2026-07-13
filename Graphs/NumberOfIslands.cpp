// LC 200: Number of Islands (Medium)
// Link: https://leetcode.com/problems/number-of-islands/
// Approach: BFS traversal. Marks visited cells as '0' in-place.
// Time: O(m * n) where m and n are grid dimensions.
// Space: O(min(m, n)) for the BFS queue.

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int &count, int r, int c) {
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        count++;
        grid[r][c] = '0'; // Mark starting cell as visited

        queue<pair<int,int>> q;
        q.push({r, c});

        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();

            // Visit neighbors
            for(int i = 0; i < 4; i++){
                int row = r + dr[i];
                int col = c + dc[i];

                if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == '1'){
                    q.push({row, col});
                    grid[row][col] = '0'; // Mark as visited immediately when pushing
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(grid, count, i, j);
                }
            }
        }
        return count;
    }
};

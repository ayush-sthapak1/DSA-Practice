// LC 130: Surrounded Regions (Medium)
// Link: https://leetcode.com/problems/surrounded-regions/
// Approach: Boundary DFS traversal. Mark boundary-connected 'O's as 'a',
//           then flip unvisited 'O's to 'X' and restore 'a' back to 'O'.
// Time: O(m * n) where m and n are board dimensions.
// Space: O(m * n) in the worst case for recursion stack.

class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c, vector<int>& dr, vector<int>& dc) {
        board[r][c] = 'a';

        for(int i = 0; i < 4; i++) {
            int row = r + dr[i]; 
            int col = c + dc[i];

            if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == 'O') {
                dfs(board, row, col, dr, dc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        // Traverse boundaries and run DFS for any boundary 'O'
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0, dr, dc);
            if(board[i][n - 1] == 'O') dfs(board, i, n - 1, dr, dc);
        }
        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') dfs(board, 0, i, dr, dc);
            if(board[m - 1][i] == 'O') dfs(board, m - 1, i, dr, dc);
        }

        // Final scan: flip unvisited 'O's to 'X', restore 'a' to 'O'
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'a') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};

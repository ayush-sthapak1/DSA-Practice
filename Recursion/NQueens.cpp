// LC 51: N-Queens (Hard)
// Approach: Backtracking with O(1) Column and Diagonal Lookups
// Time: O(N!)  Space: O(N)

class Solution {
public:
    void solve(int r, int n, vector<string>& board, vector<vector<string>>& result,
               vector<bool>& cols, vector<bool>& diagLeft, vector<bool>& diagRight) {
        // Base case: All rows successfully placed
        if (r == n) {
            result.push_back(board);
            return;
        }

        // Try placing a Queen in every column 'c' of row 'r'
        for (int c = 0; c < n; c++) {
            int d1 = r - c + n - 1; // Index for up-left diagonal (\)
            int d2 = r + c;         // Index for up-right diagonal (/)

            // O(1) Safety Check
            if (cols[c] || diagLeft[d1] || diagRight[d2]) {
                continue; // Under attack, skip this column
            }

            // Action: Place Queen & Block paths
            board[r][c] = 'Q';
            cols[c] = true;
            diagLeft[d1] = true;
            diagRight[d2] = true;

            // Recurse to next row
            solve(r + 1, n, board, result, cols, diagLeft, diagRight);

            // Backtrack: Remove Queen & Restore paths
            board[r][c] = '.';
            cols[c] = false;
            diagLeft[d1] = false;
            diagRight[d2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        // Lookup arrays for O(1) safety checks
        vector<bool> cols(n, false);
        vector<bool> diagLeft(2 * n - 1, false);
        vector<bool> diagRight(2 * n - 1, false);

        solve(0, n, board, result, cols, diagLeft, diagRight);
        return result;
    }
};

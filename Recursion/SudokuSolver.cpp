// LC 37: Sudoku Solver (Hard)
// Approach: Grid Backtracking with Optimal 9-Iteration Single-Loop Safety Check
// Time: O(9^k) where k is the number of empty cells (at most 81)
// Space: O(81) recursion stack depth

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char val) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[r][i] == val) return false;
            
            // Check column
            if (board[i][c] == val) return false;
            
            // Check 3x3 subgrid using division and modulo mapping
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int r, int c) {
        // Base case: All rows filled successfully
        if (r == 9) {
            return true;
        }

        // Wrap to the next row when we reach the end of column 9
        if (c == 9) {
            return solve(board, r + 1, 0);
        }

        // Skip pre-filled cells and move to next column
        if (board[r][c] != '.') {
            return solve(board, r, c + 1);
        }

        // Try placing digits '1' to '9' in the current empty cell
        for (int i = 1; i <= 9; i++) {
            char val = '0' + i;

            if (isValid(board, r, c, val)) {
                board[r][c] = val; // Action: Place digit

                // Recurse to next cell
                if (solve(board, r, c + 1)) {
                    return true;
                }

                board[r][c] = '.'; // Backtrack: Restore state
            }
        }

        return false; // Trigger backtracking to previous cell
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

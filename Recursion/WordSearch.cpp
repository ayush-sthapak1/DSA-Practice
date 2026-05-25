// LC 79: Word Search
// Approach: In-place Grid Backtracking (DFS) with logical short-circuiting
// Time: O(N * M * 3^L)  Space: O(L)

class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // Boundary check and mismatch pruning
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        // Base case: successfully matched the complete word
        if (index == (int)word.size() - 1) {
            return true;
        }

        // Save current character and mark visited in-place
        char temp = board[r][c];
        board[r][c] = '#';

        // 4-directional search using compiler short-circuiting (stops exploring once true is found)
        bool next = solve(board, word, r, c + 1, index + 1) ||
                    solve(board, word, r + 1, c, index + 1) ||
                    solve(board, word, r, c - 1, index + 1) ||
                    solve(board, word, r - 1, c, index + 1);

        // Restore state (Backtrack)
        board[r][c] = temp;
        return next;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        // Initiate search from every possible starting coordinate
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

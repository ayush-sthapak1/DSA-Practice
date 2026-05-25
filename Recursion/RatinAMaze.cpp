// GFG: Rat in a Maze
// Approach: In-place Grid Backtracking (DFS) with O(1) String Memory Allocation
// Time: O(4^(N^2))  Space: O(N^2) stack depth

class Solution {
public:
    int n;

    void solve(int r, int c, vector<vector<int>>& maze, vector<string>& result, string& path) {
        // Boundary and obstacle check
        if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0) {
            return;
        }

        // Base case: Reached the destination
        if (r == n - 1 && c == n - 1) {
            result.push_back(path);
            return;
        }

        // Mark current cell as visited in-place
        maze[r][c] = 0;

        // Explore D -> L -> R -> U (Lexicographical order)
        // Down
        path.push_back('D');
        solve(r + 1, c, maze, result, path);
        path.pop_back(); // Backtrack

        // Left
        path.push_back('L');
        solve(r, c - 1, maze, result, path);
        path.pop_back(); // Backtrack

        // Right
        path.push_back('R');
        solve(r, c + 1, maze, result, path);
        path.pop_back(); // Backtrack

        // Up
        path.push_back('U');
        solve(r - 1, c, maze, result, path);
        path.pop_back(); // Backtrack

        // Unmark current cell (Backtrack)
        maze[r][c] = 1;
    }

    vector<string> findPath(vector<vector<int>>& maze) {
        n = maze.size();
        vector<string> result;
        string path = "";

        // Check if starting or ending cell is blocked
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return {};
        }

        solve(0, 0, maze, result, path);
        return result;
    }
};

// LC 1631: Path With Minimum Effort (Medium)
// Link: https://leetcode.com/problems/path-with-minimum-effort/
// Approach: Dijkstra's Algorithm on a grid using a Min-Priority Queue.
//           Minimizes the maximum height difference along the path.
// Time: O(m * n * log(m * n)) where m and n are grid dimensions.
// Space: O(m * n) for the effort matrix and priority queue.

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Min-Priority Queue storing {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> effortArr(m, vector<int>(n, INT_MAX));
        effortArr[0][0] = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            // Prune stale queue entries
            if (effort > effortArr[row][col]) continue;
            
            // Early return when destination is reached
            if (row == m - 1 && col == n - 1) return effort;

            for(int i = 0; i < dr.size(); i++){
                int r = row + dr[i];
                int c = col + dc[i];

                if(r >= 0 && r < m && c >= 0 && c < n){
                    int eff = abs(heights[row][col] - heights[r][c]);
                    int currEff = max(eff, effort); // Effort along this path is the max jump
                    
                    if(currEff < effortArr[r][c]){
                        effortArr[r][c] = currEff;
                        pq.push({currEff, {r, c}});
                    }
                }
            }
        }
        return effortArr[m-1][n-1];
    }
};

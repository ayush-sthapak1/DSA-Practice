// LC 733: Flood Fill (Easy)
// Link: https://leetcode.com/problems/flood-fill/
// Approach: BFS traversal starting from target cell.
//           Early return guard for initColor == color prevents infinite loop.
// Time: O(m * n) where m and n are image dimensions.
// Space: O(m * n) in the worst case for queue.

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        if (initColor == color) return image;
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        
        int dRow[] = {-1,1,0,0};
        int dCol[] = {0,0,-1,1};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int d = 0; d < 4; d++){
                int ni = i + dRow[d];
                int nj = j + dCol[d];

                if(ni >= 0 && ni < image.size() && nj >= 0 && nj < image[0].size() && image[ni][nj] == initColor){
                    image[ni][nj] = color;
                    q.push({ni,nj});
                }
            }
        }

        return image;
    }
};

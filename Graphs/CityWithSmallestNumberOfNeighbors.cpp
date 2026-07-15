// LC 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance (Medium)
// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Approach: Floyd-Warshall algorithm to find all-pairs shortest paths.
//           Then count reachable neighbors for each city within the threshold.
// Time: O(n^3) where n is the number of cities.
// Space: O(n^2) to store the distance matrix.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize edge weights
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Distance from a city to itself is 0
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        // Floyd-Warshall all-pairs shortest path
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int city = -1;
        int minNbrs = INT_MAX;

        // Find the city with the smallest number of neighbors within distanceThreshold
        for(int i = 0; i < n; i++){
            int currentNbrs = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    currentNbrs++;
                }
            }
            
            // <= ensures we pick the city with the largest index in case of a tie
            if(currentNbrs <= minNbrs){
                minNbrs = currentNbrs;
                city = i;
            }
        }
        return city;
    }
};

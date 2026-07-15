// LC 1976: Number of Ways to Arrive at Destination (Medium)
// Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// Approach: Dijkstra's Algorithm combined with dynamic programming (ways array).
//           Maintains a ways[i] count of the number of shortest paths to node i.
// Time: O(E * log V) where V is n and E is the size of roads.
// Space: O(V + E) to build adjacency list, and O(V) for distance/ways arrays and queue.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        
        // Build bidirectional weighted adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Min-Priority Queue storing {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        vector<long long> distArray(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        
        pq.push({0, 0});
        distArray[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Prune stale queue entries
            if (dist > distArray[node]) continue;

            for (auto nbr : adj[node]) {
                int nbrNode = nbr.first;
                long long edgeWeight = nbr.second;

                long long currDist = dist + edgeWeight;

                // Case 1: Found a strictly shorter path
                if (currDist < distArray[nbrNode]) {
                    distArray[nbrNode] = currDist;
                    ways[nbrNode] = ways[node]; // Inherit all paths leading to current node
                    pq.push({currDist, nbrNode});
                }
                // Case 2: Found an alternative path of the exact same shortest length
                else if (currDist == distArray[nbrNode]) {
                    ways[nbrNode] = (ways[nbrNode] + ways[node]) % MOD; // Add alternative ways
                }
            }
        }
        
        return ways[n - 1];
    }
};

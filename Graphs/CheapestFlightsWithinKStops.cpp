// LC 787: Cheapest Flights Within K Stops (Medium)
// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Approach: BFS using a standard queue to traverse level-by-level (by stops).
//           Prevents path propagation once stops limit is exceeded.
// Time: O(V + E) where V is vertices and E is edges (flights).
// Space: O(V + E) to build adjacency list, and O(V) for queue/priceArray.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list (directed weighted graph)
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }

        // Queue stores {stops, {city, current_price}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        vector<int> priceArray(n, INT_MAX);
        priceArray[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int city = q.front().second.first;
            int cityPrice = q.front().second.second;
            q.pop();

            // If we have already reached the stop limit, do not propagate further
            if(stops > k) continue;

            for(auto nbr : adj[city]){
                int dest = nbr.first;
                int destPrice = nbr.second;

                // Relaxation condition: only update and enqueue if we found a cheaper price
                if(cityPrice + destPrice < priceArray[dest]){
                    priceArray[dest] = cityPrice + destPrice;
                    q.push({stops + 1, {dest, priceArray[dest]}});
                }
            }
        }
        
        return priceArray[dst] == INT_MAX ? -1 : priceArray[dst];
    }
};

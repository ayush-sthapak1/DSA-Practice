// LC 743: Network Delay Time (Medium)
// Link: https://leetcode.com/problems/network-delay-time/
// Approach: Dijkstra's algorithm from source node k to find the shortest times to all other nodes.
// Time: O(E * log V) where V is n and E is the size of times.
// Space: O(V + E) to build adjacency list, and O(V) for queue/time array.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build directed adjacency list (1-based indexing)
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }
        
        // Min-Priority Queue storing {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> timeArr(n + 1, INT_MAX);
        
        pq.push({0, k});
        timeArr[k] = 0;

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Prune stale queue entries
            if (time > timeArr[node]) continue;

            for(auto nbr : adj[node]){
                int nbrNode = nbr.first;
                int edgeTime = nbr.second;

                int currTime = time + edgeTime; 
                
                // Relaxation step
                if(currTime < timeArr[nbrNode]){
                    timeArr[nbrNode] = currTime;
                    pq.push({currTime, nbrNode});
                }
            }
        }
        
        // Find the maximum time to reach any node, or return -1 if any node is unreachable
        int totalTime = 0;
        for (int i = 1; i <= n; i++) {
            if (timeArr[i] == INT_MAX) return -1;
            totalTime = max(totalTime, timeArr[i]);
        }
        
        return totalTime;
    }
};

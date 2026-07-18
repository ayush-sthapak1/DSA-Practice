// GFG: Minimum Spanning Tree - Kruskal's Algorithm (Medium)
// Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Approach: Kruskal's Algorithm. Sort all edges by weight and use Disjoint Set Union (DSU)
//           with Union by Rank and Path Compression to avoid cycle formation.
// Time: O(E * log E + E * alpha(V)) where V is vertices and E is edges.
// Space: O(V + E) to store edge list and parent/rank vectors for DSU.

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Initialize DSU for n elements (1-based indexing supported)
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); // Ultimate parent of u
        int ulp_v = findUPar(v); // Ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in same set

        // Attach shorter rank tree under taller rank tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } 
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } 
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int, pair<int, int>>> edgeList;
        
        // Transform edge list to {weight, {u, v}} for automatic sorting
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            edgeList.push_back({w, {u, v}});
        }
        
        // Sort edges in ascending order of their weights
        sort(edgeList.begin(), edgeList.end());
        int mstWeight = 0;
        DisjointSet ds(V);
        
        for(auto edge : edgeList){
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            // If the endpoints belong to different components, pick this edge
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWeight += wt;
                ds.unionByRank(u, v);
            }
        }
        return mstWeight;
    }
};

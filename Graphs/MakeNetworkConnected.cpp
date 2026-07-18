// LC 1319: Number of Operations to Make Network Connected (Medium)
// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Approach: DSU to group connected nodes into components.
//           Minimum cables to connect C components is C - 1, provided total edges >= n - 1.
// Time: O(V + E * alpha(V)) where V is n and E is connections.
// Space: O(V) for DSU parent and rank arrays.

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // A graph with n nodes requires at least n - 1 edges to be fully connected
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);

        // Union connected computer pairs
        for (const auto& connection : connections) {
            ds.unionByRank(connection[0], connection[1]);
        }

        // Count number of independent network components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) {
                components++;
            }
        }

        // To connect C components, we need C - 1 cables
        return components - 1;
    }
};

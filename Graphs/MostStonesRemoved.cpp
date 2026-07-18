// LC 947: Most Stones Removed with Same Row or Column (Medium)
// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Approach: DSU grouping rows and columns as nodes. Column indices are offset
//           to prevent clashes. Max removed = Total Stones - Number of components.
// Time: O(N + V * alpha(V)) where N is number of stones, and V is maxRows + maxCols.
// Space: O(V) for DSU parent/rank arrays and map.

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
    int removeStones(vector<vector<int>>& stones) {
        int maxRows = 0;
        int maxCols = 0;

        for (auto stone : stones) {
            maxRows = max(maxRows, stone[0]);
            maxCols = max(maxCols, stone[1]);
        }

        // Size DSU dynamically to fit max index used (maxRows + maxCols + 1)
        DisjointSet ds(maxRows + maxCols + 1);
        unordered_map<int, int> stoneNodes; // To track active row/col nodes containing a stone

        for (auto stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRows + 1; // Offset col to prevent coordinate overlap with rows
            
            ds.unionByRank(rowNode, colNode);
            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        // Count unique ultimate parents (independent components C)
        int components = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                components++;
            }
        }
        
        // Maximum stones removed is Total Stones - C
        return stones.size() - components;
    }
};

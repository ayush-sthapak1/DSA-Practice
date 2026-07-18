// Standard DSU Template: Disjoint Set Union by Rank and Path Compression
// Approach: Path Compression in find() + Union by Rank in union().
// Time Complexity: O(alpha(N)) amortized per operation (inverse Ackermann function, ~O(1)).
// Space Complexity: O(N) to store parent and rank arrays.

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

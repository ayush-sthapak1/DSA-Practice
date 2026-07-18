// GFG: Disjoint Set (Union-Find) Queries (Medium)
// Link: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
// Approach: DSU with Path Compression. The Union operation is custom-constrained
//           by the query rules: always make rootX point to rootZ.
// Time: O(Q * alpha(N)) where Q is queries and alpha is inverse Ackermann function.
// Space: O(N) for parent array.

class Solution {
private:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i], parent); // Path compression
    }

public:
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        vector<int> ans;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                // Union operation: merge representative of x into representative of z
                int x = q[1];
                int z = q[2];
                
                int rootX = find(x, parent);
                int rootZ = find(z, parent);
                
                if (rootX != rootZ) {
                    parent[rootX] = rootZ; // Direct assignment forced by query
                }
            } 
            else if (q[0] == 2) {
                // Find operation: output representative of x
                int x = q[1];
                ans.push_back(find(x, parent));
            }
        }
        
        return ans;
    }
};

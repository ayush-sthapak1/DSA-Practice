// LC 721: Accounts Merge (Medium)
// Link: https://leetcode.com/problems/accounts-merge/
// Approach: DSU to group account indices. Map emails to their first-seen account index
//           and perform union when duplicate emails are encountered.
// Time: O(N * L * log(N * L)) where N is accounts, L is average emails per account (sorting dominates).
// Space: O(N * L) to store emails in map and DSU.

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mapMailNode; // Maps email to its representative account index
        DisjointSet ds(n);

        // Step 1: Map emails to account index and union duplicate email accounts
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionByRank(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Group emails under their ultimate representative account parent
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        
        // Step 3: Sort emails and build final answer format with names
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
                
            sort(mergedMail[i].begin(), mergedMail[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]); // Push the name
            for (auto it : mergedMail[i]) {
                temp.push_back(it); // Push the sorted emails
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

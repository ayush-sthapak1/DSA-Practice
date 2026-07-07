// GFG: Top View of Binary Tree (Medium)
// Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Approach: BFS (Level Order Traversal) tracking column index. 
//           We record the first node we encounter for each column into a sorted std::map.
// Time: O(N log K) where K is the number of columns (width of tree), since we do a map lookup/insertion for each node.
// Space: O(N) auxiliary space for the BFS queue and the columns map


class Solution {
  public:
    vector<int> topView(Node *root) {
        if (root == nullptr) return {};
        
        queue<pair<int, Node*>> q;
        map<int, int> cols; // maps column index -> node data
        vector<int> result;
        q.push({0, root});

        while (!q.empty()) {
            int sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                auto temp = q.front();
                int col = temp.first;
                Node* node = temp.second;
                q.pop();

                // If this is the first time we see this column, record it
                if (cols.find(col) == cols.end()) {
                    cols[col] = node->data;
                }

                if (node->left) q.push({col - 1, node->left});
                if (node->right) q.push({col + 1, node->right});
            }
        }
        
        // Copy the sorted column elements to result
        for (auto& [key, value] : cols) {
            result.push_back(value);
        }

        return result;
    }
};

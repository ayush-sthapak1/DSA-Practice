// GFG: Bottom View of Binary Tree (Medium)
// Approach: BFS (Level Order Traversal) tracking column index. 
//           We record and overwrite the node value for each column in a sorted std::map.
// Time: O(N log K) where K is the width of the tree (number of columns).
// Space: O(N) auxiliary space for the BFS queue and the columns map

#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;

#ifndef NODE_DEFINITION
#define NODE_DEFINITION
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
#endif

class Solution {
  public:
    vector<int> bottomView(Node *root) {
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

                // Overwrite with the latest (lowest) node in this column
                cols[col] = node->data;

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

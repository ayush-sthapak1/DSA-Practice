// LC 662: Maximum Width of Binary Tree (Medium)
// Approach: BFS (Level Order Traversal) with 0-based heap-like indexing.
//           To prevent integer overflow, we normalize indices of each level by subtracting the minimum index.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(N) auxiliary space to store nodes in the queue.

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> idx;
        idx.push({root, 1});

        while (!idx.empty()) {
            int sz = idx.size();
            long long minIdx = idx.front().second;
            long long maxIdx = idx.back().second;
            maxWidth = max(maxWidth, maxIdx - minIdx + 1);

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = idx.front().first;
                long long currIdx = idx.front().second - minIdx;

                if (curr->left) idx.push({curr->left, 2 * currIdx});
                if (curr->right) idx.push({curr->right, 2 * currIdx + 1});

                idx.pop();
            }
        }
        return maxWidth;
    }
};

// LC 100: Same Tree (Easy)
// Link: https://leetcode.com/problems/same-tree/
// Approach: Recursive Depth-First Search (DFS) with Short-Circuit Logic
// Time: O(N) where N is the minimum number of nodes between the two trees
// Space: O(H) where H is the height of the smaller tree (recursion stack depth)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both nodes are null (reached bottom identically)
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Base case 2: One node is null and the other is not (structural mismatch)
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // The current subtree is identical if:
        // 1. Current values match
        // 2. Left subtrees match
        // 3. Right subtrees match
        return (p->val == q->val) && 
               isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};

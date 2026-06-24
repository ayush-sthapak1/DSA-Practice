// LC 103: Binary Tree Zigzag Level Order Traversal (Medium)
// Approach: Double-Ended Queue (Deque) for Level-by-Level Alternating Directions
// Time: O(N) where N is the number of nodes in the binary tree
// Space: O(N) for storing tree nodes in the deque

#include <vector>
#include <deque>
using namespace std;

#ifndef TREE_NODE_DEFINITION
#define TREE_NODE_DEFINITION
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<vector<int>> result;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int flag = 0; // 0 for Left-to-Right, 1 for Right-to-Left

        while (!dq.empty()) {
            int sz = dq.size();
            vector<int> lvl;

            for (int i = 0; i < sz; i++) {
                if (flag == 0) {
                    TreeNode* front = dq.front();
                    dq.pop_front();
                    if (front->left != nullptr) dq.push_back(front->left);
                    if (front->right != nullptr) dq.push_back(front->right);
                    lvl.push_back(front->val);
                } else {
                    TreeNode* back = dq.back();
                    dq.pop_back();
                    if (back->right != nullptr) dq.push_front(back->right);
                    if (back->left != nullptr) dq.push_front(back->left);
                    lvl.push_back(back->val);
                }
            }
            // Toggle direction flag for the next level
            flag = 1 - flag;
            result.push_back(lvl);
        }
        return result;
    }
};

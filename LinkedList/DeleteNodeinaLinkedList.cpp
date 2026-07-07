// LeetCode 237: Delete Node in a Linked List
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Approach: Copy next node's value and bypass it
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

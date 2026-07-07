// LeetCode 876: Middle of the Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Approach: Fast and Slow Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

 // LeetCode 141: Linked List Cycle
// Approach: Fast and Slow Pointer (Floyd’s Cycle Detection)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

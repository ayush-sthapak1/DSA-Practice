// LeetCode 19: Remove Nth Node From End of List
// Approach: Two pointers with dummy node
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* ptr1 = &dummy;
        ListNode* ptr2 = &dummy;

        // Move ptr2 n steps ahead
        while (n > 0) {
            ptr2 = ptr2->next;
            n--;
        }

        // Move both pointers until ptr2 reaches end
        while (ptr2 != nullptr && ptr2->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // Remove nth node from end
        ptr1->next = ptr1->next->next;

        return dummy.next;
    }
};

// LeetCode 328: Odd Even Linked List
// Approach: Pointer skipping (build odd & even chains)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;   // odd skips even
            odd = odd->next;

            even->next = odd->next;  // even skips odd
            even = even->next;
        }

        odd->next = evenHead; // attach even list after odd list
        return head;
    }
};

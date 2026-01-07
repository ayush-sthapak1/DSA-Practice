// LeetCode 148: Sort List
// Approach: Merge Sort on Linked List
// Time Complexity: O(n log n)
// Space Complexity: O(log n) [recursion stack]

class Solution {
public:
    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoSortedLists(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        temp->next = left ? left : right;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findmid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        right = sortList(right);

        return mergeTwoSortedLists(left, right);
    }
};

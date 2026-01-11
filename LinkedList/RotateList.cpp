// LeetCode 61: Rotate List
// Approach: Convert to circular list
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* tail = head;
        int n = 1;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k %= n;
        if (k == 0) return head;

        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};
// LeetCode 61: Rotate List
// Approach: Convert to circular list
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* tail = head;
        int n = 1;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k %= n;
        if (k == 0) return head;

        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};

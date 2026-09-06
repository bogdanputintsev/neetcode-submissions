/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Better approach: keep distance between slow and fast pointers exactly k.
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // We keep the distance exactly k.
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Fast is nullptr when n is the size of linked list
        if (!fast) {
            return head->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};

// 1 2
// .
//   .

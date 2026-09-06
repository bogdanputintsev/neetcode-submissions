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
        if (!head || !head->next) {
            return nullptr;
        }

        int size = 1;
        ListNode* curr = head;

        while ((curr = curr->next)) {
            size++;
        }

        if (n == size) {
            return head->next;
        }

        curr = head;
        int steps = 0;
        while (curr) {
            if (curr->next && steps + 1 == size - n) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
            steps++;
        }

        return head;
    }
};

// 1 2 3 4
//   .
// s = 4
// n = 1
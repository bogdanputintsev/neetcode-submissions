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
    void reorderList(ListNode* head) {
        int steps = 0;
        int maxSteps = 0;
        
        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* tail = curr;

        while((curr = curr->next)) {
            maxSteps++;
        }

        curr = head; 

        while (steps < maxSteps) {
            next = curr->next;
            tail = curr;
            for (int i = 0; i < maxSteps - steps; i++) {
                tail = tail->next;
            }

            curr->next = tail;
            if (next != tail) {
                tail->next = next;
            } else {
                tail->next = nullptr;
            }

            curr = next;
            steps+=2;
        }

        curr->next = nullptr;
    }
};

// 2->10->4->8->6

// 2 4 6 8 10
//     .
//     >
//       #



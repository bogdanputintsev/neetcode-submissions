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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* startOfNextGroup = head;
        ListNode* endOfPrevGroup = nullptr;
        
        bool firstReverse = true;
        
        while (startOfNextGroup) {
            ListNode* start = startOfNextGroup;
            ListNode* end = moveKSteps(start, k);
            if (!end) {
                if (endOfPrevGroup) {
                    endOfPrevGroup->next = start;
                }
                break;
            }
            
            startOfNextGroup = end->next;

            reverse(start, end);

            if (firstReverse) {
                head = start;
                firstReverse = false;
            }

            if (endOfPrevGroup) {
                endOfPrevGroup->next = start;
            }
            endOfPrevGroup = end;
        }

        return head;
    }

    void reverse(ListNode*& start, ListNode*& end) {
        const ListNode* const startOfNextGroup = end->next;

        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = start->next;

        while (curr != startOfNextGroup) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr != startOfNextGroup) {
                next = curr->next;
            }
        }

        end = start;
        start = prev;
    }

    ListNode* moveKSteps(ListNode* start, int k) {
        ListNode* curr = start;
        
        for (int i = 0; i < k - 1; i++) {
            curr = curr->next;
            if (!curr) {
                return nullptr;
            }
        }

        return curr;
    }
};


// 1 2 3 4 5 6
// .
//     .
// 3 2 1

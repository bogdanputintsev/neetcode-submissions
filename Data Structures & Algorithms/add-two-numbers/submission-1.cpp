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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result  = nullptr;
        ListNode* current = nullptr;

        int remainder = 0;

        while (l1 || l2 || remainder) {
            int sum = remainder;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            remainder = sum / 10;

            int digit = sum % 10;

            auto newNode = new ListNode(digit);
            if (!result) {
                result = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }

        return result;
    }
};

// 009 
// 889
//   8
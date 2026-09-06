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

        if (!head || !head->next) {
            return;
        }

        // 1. Find middle
        ListNode* middle = findMiddle(head);

        // 2. Reverse the second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = middle;
        ListNode* lastNodeBeforeSecondHalf = findPreviousNodeBefore(head, secondHalf);
        secondHalf = reverse(middle);
        lastNodeBeforeSecondHalf->next = nullptr;

        // 3. Merge two halfs
        head = mergeTwoHalfs(firstHalf, secondHalf);
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* findPreviousNodeBefore(ListNode* head, ListNode* node) {
        if (!head || !node || head == node) {
            return nullptr;
        }

        while (head->next) {
            if (head->next == node) {
                return head;
            }
            head = head->next;
        }

        return nullptr;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = head->next;

        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr) {
                next = curr->next;
            }
        }

        return prev;
    }

    ListNode* mergeTwoHalfs(ListNode* first, ListNode* second) {
        ListNode* root = first;

        while (first && second) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            first->next = second;
            if (firstNext) {
                second->next = firstNext;
            }
            first = firstNext;
            second = secondNext;
        }

        return root;
    }
};


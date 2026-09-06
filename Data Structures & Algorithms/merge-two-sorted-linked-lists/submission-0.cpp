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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        while (list1 || list2) {

            if (list1 && list2) {
                if (list1->val < list2->val) {
                   mergeNode(list1);
                } else  {
                    mergeNode(list2);
                }
            } else if (list1 && !list2) {
                mergeNode(list1);
            } else if (!list1 && list2) {
                mergeNode(list2);
            }

        }

        return root;
    }

private:
    ListNode* root = nullptr;
    ListNode* curr = nullptr;

    void mergeNode(ListNode*& node) {
        if (!root) {
            root = node;
            curr = root;
        } else {
            curr->next = node;
            curr = curr->next;
        }

        node = node->next;
    }
};

// 1 2 4
// 1 3 5
// 1 1 2 3 4 5
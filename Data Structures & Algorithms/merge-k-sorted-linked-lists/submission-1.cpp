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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        std::priority_queue<ElementResult, vector<ElementResult>, std::greater<ElementResult>> pq;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.emplace(lists[i], i);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            auto minElement = pq.top();
            pq.pop();

            ListNode* node = minElement.node;
            lists[minElement.index] = node->next;

            tail->next = node;
            tail = node;
            tail->next = nullptr;

            if (lists[minElement.index]) {
                pq.emplace(lists[minElement.index], minElement.index);
            }
        }

        return dummy.next;
    }

private:
    struct ElementResult {
        ListNode* node;
        int index;

        bool operator<(const ElementResult& other) const noexcept {
            return node->val < other.node->val;
        }

        bool operator>(const ElementResult& other) const noexcept {
            return node->val > other.node->val;
        }
    };
};


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

        std::vector<ElementResult> initialValues;
        initialValues.reserve(lists.size());
        for (std::size_t i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                initialValues.emplace_back(lists[i], i);
            }
        }

        std::priority_queue<
            ElementResult, 
            vector<ElementResult>, 
            ElementResultComparator> 
            pq(ElementResultComparator{}, std::move(initialValues));
    
        
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
        std::size_t index;
    };

    struct ElementResultComparator {
        bool operator() (const ElementResult& lhs, const ElementResult& rhs) const noexcept {
            return lhs.node->val > rhs.node->val;
        }
    };
};


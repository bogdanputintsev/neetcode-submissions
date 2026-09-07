/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> copies;

        for (Node* curr = head; curr; curr = curr->next) {
            copies.emplace(curr, new Node(curr->val));
        }

        for (Node* curr = head; curr; curr = curr->next) {
            auto copy = copies.at(curr);

            copy->next = curr->next
                ? copies.at(curr->next)
                : nullptr;
            
            copy->random = curr->random
                ? copies.at(curr->random)
                : nullptr;
        }

        return copies.at(head);
    }
};

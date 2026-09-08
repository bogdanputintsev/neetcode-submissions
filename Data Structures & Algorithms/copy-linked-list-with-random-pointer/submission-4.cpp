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
    // Cool inplace solution: 1 -> 1' -> 2 -> 2' -> ...
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        
        for (Node* curr = head; curr; curr = curr->next->next) {
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
        }

        for (Node* curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        Node* copy = head->next;
        for (Node* curr = head; curr; curr = curr->next) {
            Node* next = curr->next;

            curr->next = curr->next->next;
            if (next->next) {
                next->next = next->next->next;
            }
        }

        return copy;
    }
};

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
            copies[curr] = new Node(curr->val);
        }

        for (Node* curr = head; curr; curr = curr->next) {
            Node* copy = copies[curr];

            copy->next = curr->next
                ? copies[curr->next]
                : nullptr;
            
            copy->random = curr->random
                ? copies[curr->random]
                : nullptr;
        }

        return copies[head];
    }
};

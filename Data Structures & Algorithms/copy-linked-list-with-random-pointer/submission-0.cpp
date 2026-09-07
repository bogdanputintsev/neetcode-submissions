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

        Node* copy = new Node(head->val);
        Node* oldPtr = head;
        Node* newPtr = copy;

        unordered_map<Node*, size_t> ids;

        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            ids[curr] = ids.size();
        }
        
        vector<optional<int>> randomMappings(ids.size());
        oldPtr = head;
        for (int i = 0; oldPtr != nullptr && i < ids.size(); oldPtr = oldPtr->next, i++) {
            if (oldPtr->random) {
                randomMappings[i] = ids[oldPtr->random];
            }
        }

        oldPtr = head;
        newPtr = copy;
        while (oldPtr->next) {
            newPtr->next = new Node(oldPtr->next->val);
            oldPtr = oldPtr->next;
            newPtr = newPtr->next;
        }

        vector<Node*> newMappings;
        newMappings.reserve(ids.size());
        for (Node* curr = copy; curr != nullptr; curr = curr->next) {
            newMappings.push_back(curr);
        }

        newPtr = copy;
        for (int i = 0; 
            newPtr != nullptr && i < newMappings.size(); 
            newPtr = newPtr->next, i++) {
            if (randomMappings[i].has_value()) {
                newPtr->random = newMappings[*randomMappings[i]];
            }
        }

        return copy;
        
    }
};

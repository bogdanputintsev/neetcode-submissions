class LRUCache {
public:
    explicit LRUCache(int capacity) :
        capacity(capacity),
        head(new Node()),
        tail(new Node()) {
        
        connect(head, tail);
        hashtable.reserve(capacity);
    }
    
    ~LRUCache() {
        Node* current = head; 
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key) {
        const auto it = hashtable.find(key);
        if (it == hashtable.cend()) {
            return NOT_FOUND;
        }

        Node* foundNode = it->second;
        moveToHead(foundNode);

        return foundNode->value;
    }
    
    void put(int key, int value) {
        auto it = hashtable.find(key);

        if (it == hashtable.end()) {
            putNew(key, value);
        } else {
            Node* foundNode = it->second;
            foundNode->value = value;
            moveToHead(foundNode);
        }
    }

private:
    struct Node final {
        Node() = default;

        explicit Node(const int key, const int value):
            key(key),
            value(value) {
        }
        
        Node* previous = nullptr;
        Node* next = nullptr;
        const int key = 0;
        int value = 0;
    };

    void disconnect(Node* node) {
        if (node->next && node->previous) {
            connect(node->previous, node->next);
            node->next = node->previous = nullptr;
        }
    }

    void connect(Node* leftNode, Node* rightNode) {
        if (leftNode && rightNode && leftNode != rightNode) {
            leftNode->next = rightNode;
            rightNode->previous = leftNode;
        }
    }

    void putNew(int key, int value) {
        Node* newNode = new Node(key, value);
        moveToHead(newNode);
        hashtable[key] = newNode;

        checkOverflow();
    }

    void checkOverflow() {
        if (hashtable.size() > capacity) {
            Node* lastElement = tail->previous;
            disconnect(lastElement);
            hashtable.erase(lastElement->key);
            delete lastElement;
        }
    }

    void moveToHead(Node* node) {
        disconnect(node);

        Node* lastNode = head->next;
        connect(head, node);
        connect(node, lastNode);
    }
 
    static constexpr int NOT_FOUND = -1;

    const int capacity = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    unordered_map<int, Node*> hashtable;
};


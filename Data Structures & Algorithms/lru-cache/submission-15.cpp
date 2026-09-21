class LRUCache final {
public:
    explicit LRUCache(int capacity) :
        capacity(max(capacity, MIN_POSSIBLE_CAPACITY)),
        head(Node()),
        tail(Node()) {
        connect(&head, &tail);
        hashtable.reserve(this->capacity);
    }
    
    ~LRUCache() {
        destroyAllNodes();
        reset();
        hashtable.clear();
    }

    LRUCache(const LRUCache& rhs) :
        capacity(rhs.capacity) {
        reset();
        hashtable.reserve(rhs.capacity);

        try {

            for (Node* current = rhs.head.next; current; current = current->next) {    
                Node* copy = new Node(current->key, current->value);
                
                try {
                    hashtable.emplace(copy->key, copy);
                } catch (...) {
                    delete copy;
                    throw;
                }

                moveToTail(copy);
            }

        } catch (...) {
            destroyAllNodes();
            throw;
        }
    }

    LRUCache& operator=(const LRUCache& rhs) {
        LRUCache temporary(rhs);
        swap(temporary);
        return *this;
    }

    LRUCache(LRUCache&& rhs) noexcept :
        capacity(rhs.capacity),
        hashtable(std::move(rhs.hashtable)) {
        reset();
        auto [first, last] = rhs.releaseChain();
        aquireChain(first, last);
        rhs.hashtable.clear();
    }

    LRUCache& operator=(LRUCache&& rhs) noexcept {
        if (this != &rhs) {
            destroyAllNodes();
            capacity = rhs.capacity;
            hashtable = std::move(rhs.hashtable);
            rhs.hashtable.clear();
            auto [first, last] = rhs.releaseChain();
            aquireChain(first, last);
        }

        return *this;
    }

    void swap(LRUCache& other) noexcept {
        auto mine = releaseChain();
        auto theirs = other.releaseChain();

        aquireChain(theirs.first, theirs.second);
        other.aquireChain(mine.first, mine.second);

        hashtable.swap(other.hashtable);
        std::swap(capacity, other.capacity);
    }

    friend void swap(LRUCache& lhs, LRUCache& rhs) noexcept {
        lhs.swap(rhs);  
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

    int getCapacity() const noexcept { return capacity; }

private:
    struct Node final {
        Node() = default;

        explicit Node(const int key, const int value):
            key(key),
            value(value) {
        }
        
        Node* previous = nullptr;
        Node* next = nullptr;
        int key = 0;
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

        try {
            hashtable.emplace(key, newNode);
        }
        catch (...) {
            delete newNode;
            throw;
        }

        moveToHead(newNode);
        checkOverflow();
    }

    void checkOverflow() {
        if (hashtable.size() > capacity) {
            Node* lastElement = tail.previous;
            disconnect(lastElement);
            hashtable.erase(lastElement->key);
            delete lastElement;
        }
    }

    void moveToHead(Node* node) {
        disconnect(node);

        connect(node, head.next);
        connect(&head, node);
    }

    void moveToTail(Node* node) {
        disconnect(node);

        connect(tail.previous, node);
        connect(node, &tail);
    }

    void destroyAllNodes() noexcept {
        for (Node* current = head.next; current != &tail;) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void reset() noexcept {
        connect(&head, &tail);
        head.previous = nullptr;
        tail.next = nullptr;
    }

    std::pair<Node*, Node*> releaseChain() noexcept {
        if (head.next == &tail) {
            return { nullptr, nullptr };
        }

        Node* const first = head.next;
        Node* const last = tail.previous;
        reset();
        return { first, last };
    }

    void aquireChain(Node* first, Node* last) noexcept {
        if (first == nullptr) {
            destroyAllNodes();
            reset();
            return;
        }

        connect(&head, first);
        connect(last, &tail);
    }
 
    static constexpr int NOT_FOUND = -1;
    static constexpr int MIN_POSSIBLE_CAPACITY = 1;

    int capacity = 0;
    Node head;
    Node tail;

    unordered_map<int, Node*> hashtable;
};


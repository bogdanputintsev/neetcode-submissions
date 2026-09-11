class Node final {
public:
    Node() = default;

    explicit Node(const int key, const int value):
        key(key),
        value(value) {
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* newNext) {
        next = newNext;
        newNext->previous = this;
    }

    void putNext(Node* nextNode) {
        Node* lastNode = getNext();
        setNext(nextNode);
        nextNode->setNext(lastNode);
    }

    void pullOut() {
        Node* nextNode = getNext();
        getPrevious()->setNext(nextNode);
    }

    Node* getPrevious() const {
        return previous;
    }

    int getKey() const noexcept {
        return key;
    }
    
    int getValue() const noexcept {
        return value;
    }
    
    void setValue(const int newValue) {
        value = newValue;
    }

private:
    Node* previous = nullptr;
    Node* next = nullptr;
    const int key = 0;
    int value = 0;
};

class LRUCache {
public:
    explicit LRUCache(int capacity) :
        capacity(capacity),
        head(new Node()),
        tail(new Node()) {
        head->setNext(tail);
        hashtable.reserve(capacity);
    }
    
    int get(int key) {
        const auto it = hashtable.find(key);
        if (it == hashtable.cend()) {
            return NOT_FOUND;
        }

        Node* foundNode = it->second;
        foundNode->pullOut();
        head->putNext(foundNode);

        return foundNode->getValue();
    }
    
    void put(int key, int value) {
        auto it = hashtable.find(key);

        if (it == hashtable.end()) {

            Node* newNode = new Node(key, value);
            head->putNext(newNode);

            hashtable[key] = newNode;

            if (hashtable.size() > capacity) {
                Node* lastElement = tail->getPrevious();
                lastElement->pullOut();
                hashtable.erase(lastElement->getKey());
                delete lastElement;
            }

        } else {

            Node* foundNode = it->second;
            foundNode->setValue(value);

            foundNode->pullOut();

            head->putNext(foundNode);
        }
    }

private:
    static constexpr int NOT_FOUND = -1;

    const int capacity = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    unordered_map<int, Node*> hashtable;
};

// { (1, 10) }

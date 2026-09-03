class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (hashmap[key].empty()) {
            hashmap[key].reserve(MAX_POSSIBLE_TIMESTAMP);
        }

        hashmap[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        if (!hashmap.contains(key)) {
            return "";
        }

        vector<Node>& nodes { hashmap[key] };
        if (nodes[0].timestamp > timestamp) {
            return "";
        }

        int left = 0;
        int right = nodes.size();

        while (left < right) {

            int mid = left + ((right - left) / 2);

            if (nodes[mid].timestamp <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nodes[right - 1].value;
    }

private:
    static constexpr size_t MAX_POSSIBLE_TIMESTAMP = 2000000;

    struct Node {
        string value;
        int timestamp;
    };

    unordered_map<string, vector<Node>> hashmap;
};

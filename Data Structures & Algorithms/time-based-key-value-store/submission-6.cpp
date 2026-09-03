class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto it = hashmap.find(key);
        if (it == hashmap.end()) {
            return "";
        }

        vector<Node>& nodes { it->second };

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

        if (left == 0) {
            return "";
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

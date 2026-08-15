struct Element {
    int num;
    int frequency;
};

struct ElementComparator {
    bool operator()(const Element& lhs, const Element& rhs) const {
        return lhs.frequency > rhs.frequency;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencies;
        for (int num : nums) {
            frequencies[num]++;
        }

        priority_queue<Element, vector<Element>, ElementComparator> pq;
        for (const auto[num, frequency] : frequencies) {
            pq.emplace(num, frequency);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k && i < frequencies.size(); i++) {
            result.push_back(pq.top().num);
            pq.pop();
        }

        return result;
    }
};

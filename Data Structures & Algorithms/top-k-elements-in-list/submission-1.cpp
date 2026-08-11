
struct Element
{
    int value;
    int frequency;
};

struct FrequencyComparator
{
    bool operator()(const Element& lhv, const Element& rhv) const {
        return lhv.frequency > rhv.frequency;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (int num : nums) {
            hashMap[num]++;
        }

        priority_queue<Element, vector<Element>, FrequencyComparator> heap;
        for (const auto& [value, frequency] : hashMap) {
            heap.emplace(Element{value, frequency});

            if (heap.size() > k)
                heap.pop();
        }

        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; i++) {
            result.push_back(heap.top().value);
            heap.pop();
        }

        return result;
    }
};

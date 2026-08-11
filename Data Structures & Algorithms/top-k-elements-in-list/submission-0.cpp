
struct Element
{
    int value;
    size_t frequency;
};

struct FrequencyComparator
{
    bool operator()(const Element& lhv, const Element& rhv) {
        return lhv.frequency < rhv.frequency;
    }

};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, size_t> hashMap;
        for (int num : nums) {
            hashMap[num]++;
        }

        priority_queue<Element, vector<Element>, FrequencyComparator> heap;
        for (const auto& [value, frequency] : hashMap) {
            heap.push(Element(value, frequency));
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(heap.top().value);
            heap.pop();
        }

        return result;
    }
};

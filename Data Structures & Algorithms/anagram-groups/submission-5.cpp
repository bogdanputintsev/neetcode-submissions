class HashArray {
public:
    size_t operator()(const array<int, 26>& arr) const {
        size_t hash = 0;
        for (int value : arr)
            hash = hash * 31 + std::hash<int>{}(value);

        return hash;
    }
};

class Solution {
public:
    array<int, 26> calculateKey(const string& str) {
        array<int, 26> key{};

        for (const char ch : str) {
            key[ch - 'a']++;
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, HashArray> hashMap;
        hashMap.reserve(strs.size());
        
        for (auto& str : strs) {
            hashMap[calculateKey(str)].push_back(std::move(str));
        }

        vector<vector<string>> result;
        result.reserve(hashMap.size());

        for (auto& [key, value] : hashMap) {
            result.push_back(std::move(value));
        }

        return result;
    }
};

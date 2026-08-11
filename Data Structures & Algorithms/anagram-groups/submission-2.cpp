class Solution {
public:
    size_t hashString(string str)
    {
        std::hash<string> hasher;
        std::sort(str.begin(), str.end());
        return hasher(str);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;
        std::unordered_map<size_t, vector<string>> hashGroups;

        hashGroups.reserve(strs.size());
        for (auto& str : strs)
        {
            size_t hashKey = hashString(str);
            hashGroups[hashKey].push_back(std::move(str));
        }

        result.reserve(hashGroups.size());
        for (const auto& [hashKey, anagramList] : hashGroups)
        {
            result.push_back(std::move(anagramList));
        }

        return result;
    }
};

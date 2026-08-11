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

        for (auto& str : strs)
        {
            size_t hashKey = hashString(str);

            auto it = hashGroups.find(hashKey);
            if (it != hashGroups.end())
            {
                it->second.push_back(std::move(str));
            }
            else
            {
                hashGroups[hashKey] = { str };
            }
        }

        result.reserve(hashGroups.size());
        for (const auto& [hashKey, anagramList] : hashGroups)
        {
            result.emplace_back(anagramList);
        }

        return result;
    }
};

class Solution {
public:
    std::string getKey(const std::string& str)
    {
        std::array<int, 26> key{};
        for (const char c : str)
            key[c - 'a']++;

        std::string result{};
        for (int i = 0; i < 26; i++)
        {
            if (i != 0)
                result += ",";

            result += std::to_string(key[i]);
        }

        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> hashMap;
        hashMap.reserve(strs.size());
        for (const auto& str : strs) 
            hashMap[getKey(str)].push_back(str);

        std::vector<std::vector<std::string>> result;
        result.reserve(hashMap.size());
        for (auto& [key, value] : hashMap)
        {
            result.push_back(std::move(value));
        }

        return result;
    }
};

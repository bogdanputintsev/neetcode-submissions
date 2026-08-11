class Solution {
public:
    std::string getKey(const std::string& str)
    {
        std::array<int, 26> key;
        for (const char c : str)
        {
            key[c - 'a']++;
        }

        std::string result;
        for (int i = 0; i < 26; i++)
        {
            if (i != 0)
                result += ",";

            result += key[i];
        }

        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> hashMap;

        for (const auto& str : strs) 
        {
            hashMap[getKey(str)].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(hashMap.size());
        for (const auto& [key, value] : hashMap)
        {
            result.push_back(std::move(value));
        }

        return result;
    }
};

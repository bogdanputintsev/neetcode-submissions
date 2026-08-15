class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream ss;
        
        ss << strs.size() << ' ';
        
        for (const auto& str : strs) {
            ss << str.size() << ' ';
        }

        for (const auto& str : strs) {
            ss << str;
        }

        return ss.str();
    }

    vector<string> decode(string s) {
        stringstream ss(s);
        vector<string> result;

        int resultSize;
        ss >> resultSize;
        result.reserve(resultSize);

        vector<int> stringSizes(resultSize, 0);
        for (int i = 0; i < resultSize; i++) {
            ss >> stringSizes[i];
        }

        ss.get();
        int currentPos = ss.tellg();

        for (int stringSize : stringSizes) {
            result.push_back(s.substr(currentPos, stringSize));
            currentPos += stringSize;
        }

        return result;
    }
};

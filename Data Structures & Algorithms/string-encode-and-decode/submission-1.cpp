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
        
        size_t arrayLength = 0;
        ss >> arrayLength;
        
        if (arrayLength == 0)
            return {};
        
        vector<size_t> stringLengths(arrayLength);
        for (int i = 0; i < arrayLength; i++) {
            ss >> stringLengths[i];
        }

        ss.get();

        vector<string> result;
        size_t bodyPos = ss.tellg();

        for (int i = 0; i < arrayLength; i++) {
            result.push_back(s.substr(bodyPos, stringLengths[i]));
            bodyPos += stringLengths[i];
        }

        return result;
    }
};

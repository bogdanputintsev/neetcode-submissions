class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (const char ch : s) {
            if (isOpen(ch)) {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                const char openBracketFromStack = st.top();
                const char closeBracketFromString = ch;

                if (!bracketsMatches(openBracketFromStack, closeBracketFromString)) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }

private:
    bool isClose(const char ch) { return matchingBrackets.contains(ch); }
    bool isOpen(const char ch) { return !isClose(ch); }
    bool bracketsMatches(char openBracket, char closeBracket) { 
        return matchingBrackets.at(closeBracket) == openBracket;
    };

    const unordered_map<char, char> matchingBrackets = {
        { ')', '(' },
        { '}', '{' },
        { ']', '[' }
    };
};

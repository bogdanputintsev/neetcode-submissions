class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> targetCount{};

        for (char ch : s) {
            targetCount[ch - 'a']++;
        }

        for (char ch : t) {
            if (--targetCount[ch - 'a'] < 0) {
                return false;
            }
        }

        for (int letterCount : targetCount) {
            if (letterCount != 0) {
                return false;
            }
        }

        return true;
    }
};

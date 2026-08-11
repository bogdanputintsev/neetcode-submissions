class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> letters;

        for (char letter : s)
            letters[letter]++;

        for (char letter : t)
        {
            if (!letters.contains(letter))
                return false;

            if (--letters[letter] < 0)
                return false;
        }

        for (const auto&[letter, num] : letters)
            if (num != 0)
                return false;

        return true;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;

        int left = 0;
        int right = 0;
        int longest = 0;

        while (right < s.size()) {
            while (left < right && hashmap[s[right]] > 0) {
                hashmap[s[left]]--;
                left++;
            }

            longest = max(longest, right - left + 1);

            hashmap[s[right]]++;
            right++;

        }

        return longest;
    }
};

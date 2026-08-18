class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;

        int result = 0;
        int left = 0;
        int right = 0;

        while (left < s.size() && right < s.size()) {
            hashmap[s[right]]++;

            if (hashmap[s[right]] > 1) {
                result = max(result, right - left);
                while (s[left] != s[right]) {
                    hashmap[s[left]]--;
                    left++;
                }
                hashmap[s[left]]--;
                left++;
            } 

            right++;
        }

        if (right >= s.size()) {
            result = max(result, right - left);
        }

        return result;
    }
};
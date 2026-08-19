class Solution {
   public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int left = 0;
        int right = 0;
        int maxFreq = 0;

        if (s.empty()) {
            return 0;
        }

        unordered_map<char, int> hashmap;

        while (right < s.size()) {
            hashmap[s[right]]++;

            maxFreq = max(maxFreq, hashmap[s[right]]);
           
            while ((right - left + 1) - maxFreq > k) {
                hashmap[s[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};

// 0
// BAAA
//  .
//     .

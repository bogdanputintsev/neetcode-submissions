class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> target;
        for (const char ch : s1) {
            target[ch]++;
        }

        unordered_map<char, int> current;

        int left = 0;
        int right = 0;

        while (right < s2.size()) {
            current[s2[right]]++;

            if (!target.contains(s2[right])) {
                right++;
                while (left != right) {
                    current[s2[left]]--;
                    left++;
                }
                continue;
            }
            
            while (current[s2[right]] > target[s2[right]]) {
                current[s2[left]]--;
                left++;
            }

            if ((right - left + 1) == s1.size()) {
                return true;
            }

            right++;
        }

        return false;
    }
};


// ky
// ainwkckifykxlribaypk
// .
//  .

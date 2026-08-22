class Solution {
public:
    string minWindow(string s, string t) {
        optional<int> bestDistance;
        int bestLeft = 0;
        int bestRight = 300000;
        int left = 0;
        int right = 0;
        int matches = 0;

        unordered_map<char, int> current;
        unordered_map<char, int> target;
        for (char ch : t) {
            target[ch]++;
        }

        while (left < s.size() && right < s.size()) {
            while (right < s.size()) {
                if (target.contains(s[right])) {
                    current[s[right]]++;
                    if (current[s[right]] == target[s[right]]) {
                        matches++;
                        if (matches == target.size()) {
                            if (!bestDistance.has_value() || ((right - left + 1) < *bestDistance)) {
                                bestLeft = left;
                                bestRight = right;
                                bestDistance = bestRight - bestLeft + 1;
                            }
                            break;
                        }
                    }
                }
                right++;
            }

            while (matches == target.size()) {
                if (!bestDistance.has_value() || ((right - left + 1) < *bestDistance)) {
                    bestLeft = left;
                    bestRight = right;
                    bestDistance = bestRight - bestLeft + 1;
                }
                if (target.contains(s[left])) {
                    if (current[s[left]] == target[s[left]]) {
                        matches--;
                    }
                    current[s[left]]--;
                }
                left++;
            }

            right++;
        }

        return bestDistance.has_value() 
            ? s.substr(bestLeft, bestRight - bestLeft + 1)
            : "";
    }
};


// aaaaaaaaaaaabbbbbcdd
// .
//                     .
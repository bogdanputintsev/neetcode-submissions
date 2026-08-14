class Solution {
private:
    unordered_map<int, int> sequence;
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int longest = 1;
        for (int num : nums) {
            sequence[num] = 1;
        }

        for (const auto& [num, count] : sequence) {
            int currentNum = num;
            if (!sequence.contains(currentNum - 1) || sequence[currentNum] > 1) {
                continue;
            }

            int cachedValue = 0;
            while (sequence.contains(currentNum - 1)) {
                if (sequence[currentNum - 1] != 1) {
                    cachedValue = sequence[currentNum - 1];
                    break;
                }
                currentNum--;
            }

            int maxDistance = (num - currentNum) + cachedValue + 1;
            longest = max(longest, maxDistance);

            while (currentNum <= num) {
                int currentDistance = (num - currentNum) + 1;
                sequence[currentNum] = maxDistance - currentDistance + 1;
                currentNum++;
            }
        }

        return longest;
    }
};



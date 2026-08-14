class Solution {
private:
    // [0,3,2,5,4,6,1,1]
    // { (0, 1), (3, 4), (2, 3), (5, 1), (4, 4), (6, 1), (1, 2) }
    unordered_map<int, int> sequence;
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int longest = 1; // 5
        for (int num : nums) {
            sequence[num] = 1;
        }

        for (const auto& [num, count] : sequence) {
            // (5, 1)
            int currentNum = num; // 4
            if (!sequence.contains(currentNum - 1) || sequence[currentNum] > 1) {
                continue;
            }

            int cachedValue = 0; // 4
            while (sequence.contains(currentNum - 1)) {
                if (sequence[currentNum - 1] != 1) {
                    cachedValue = sequence[currentNum - 1];
                    break;
                }
                currentNum--;
            }

            int maxDistance = (num - currentNum) + cachedValue + 1; // 6
            longest = max(longest, maxDistance);

            while (currentNum <= num) {
                int currentDistance = (num - currentNum) + 1; // 2
                sequence[currentNum] = maxDistance - currentDistance + 1;
                currentNum++;
            }
        }

        return longest;
    }
};



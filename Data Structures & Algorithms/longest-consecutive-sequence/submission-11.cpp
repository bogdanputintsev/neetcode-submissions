class Solution {
public:
        int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueNums;
        uniqueNums.reserve(nums.size());
        uniqueNums.insert(nums.begin(), nums.end());

        int maxSequenceLength = 0;

        for (int num : uniqueNums) {
            if (uniqueNums.contains(num - 1)) {
                continue;
            }

            int current = num;
            int currentLength = 1;
            while (uniqueNums.contains(current + 1)) {
                ++current;
                ++currentLength;
            }

            maxSequenceLength = max(maxSequenceLength, currentLength);
        }
  
        return maxSequenceLength;
    }
};

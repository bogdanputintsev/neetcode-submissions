class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unqueNums(nums.begin(), nums.end());
        int maxSequenceLength = 0;

        for (int num : unqueNums) {
            if (unqueNums.contains(num - 1)) {
                continue;
            }

            int currentLength = 1;
            while (unqueNums.contains(num + 1)) {
                num++;
                currentLength++;
            }

            maxSequenceLength = max(maxSequenceLength, currentLength);
        }
  
        return maxSequenceLength;
    }
};

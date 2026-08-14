class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> numbers(nums.begin(), nums.end());

        for (int num : nums) {
            if (numbers.contains(num - 1)) {
                continue;
            }

            int currentResult = 1;
            int currentNum = num;
            while (numbers.contains(currentNum + 1)) {
                currentResult++;
                currentNum++;
            }

            result = max(result, currentResult);
        }

        return result;
    }
};

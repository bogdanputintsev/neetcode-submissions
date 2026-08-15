class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueNums;
        for (int num : nums) {
            if (uniqueNums.contains(num)) {
                return true;
            }

            uniqueNums.insert(num);
        }

        return false;
    }
};
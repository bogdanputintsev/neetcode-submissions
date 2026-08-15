class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto it = hashmap.find(target - nums[i]);
            if (it == hashmap.end() || it->second == i) {
                continue;
            }

            return { i, it->second };
        }

        return { };
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // 7
        // [3, 0, 2, 4]
        // { {3, 0}, {0, 1}, {2, 2}, {} }
        std::unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashMap.find(target - nums[i]);
            if (it != hashMap.end())
                return { it->second, i };

            hashMap.insert({nums[i], i});
        }
       
        return { -1, -1 };
    }
};

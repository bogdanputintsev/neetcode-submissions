class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> appearedValues;

        for (int num : nums)
        {
            if (appearedValues.contains(num))
                return true;
            
            appearedValues.insert(num);
        }

        return false;
    }
};
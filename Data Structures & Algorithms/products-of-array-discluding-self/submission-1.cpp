class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        
        int commonProduct = 1;
        int numberOfZeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                numberOfZeros++;
            }            
            
            if (nums[i] != 0 || numberOfZeros > 1) {
                commonProduct *= nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (numberOfZeros == 0) {
                result[i] = commonProduct / nums[i];
            }
            else if (numberOfZeros == 1) {
                if (nums[i] == 0) {
                    result[i] = commonProduct;
                } 
                else {
                    result[i] = 0;
                }
            }
            else if (numberOfZeros > 1) {
                result[i] = 0;
            }
        }

        return result;
    }
};

// -1 0 1 2 3
// -6 - commonProduct

// 0 / -1 = 0
// 
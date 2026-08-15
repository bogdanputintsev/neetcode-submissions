class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            result[i] = result[i-1] * nums[i-1];
        }

        int accumulator = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= accumulator;
            accumulator *= nums[i];
        }

        return result;
    }
};

//  1  2  4  6
// 
//  1  1  2  8
// 48 24  6  1
// 48 24 12  8

//n 1  2  4  6
//r 1  1  1  1
//r 1  1  2  8

//a 12
//r   24  12  8
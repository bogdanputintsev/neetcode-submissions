class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size());
        suffix[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            suffix[i] = suffix[i - 1] * nums[i - 1];
        }

        vector<int> postfix(nums.size());
        postfix[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }

        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result[i] = suffix[i] * postfix[i];
        }

        return result;
    }
};

//  1  2 4 6
//  1  1 2 8
// 48 24 6 1
// 48 24 12 8
// 48 24 12 8

// -1  0 1 2 3
//  1 -1 0 0 0
//  0  6 6 3 1 
//  0 -6 0 0 0 
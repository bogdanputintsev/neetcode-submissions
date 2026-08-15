class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int left = 0;
            int right = nums.size() - 1;

            while (left < right) {
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }

                const int sum = nums[left] + nums[right];
                const int target = -nums[i];

                if (sum == target) {
                    vector<int> triplet {nums[left], nums[i], nums[right]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(std::move(triplet));
                    
                    if (nums[left+1] + nums[right] == target) {
                        left++;
                    }
                    else if (nums[left] + nums[right-1] == target) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
                else if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
            }
        }

        vector<vector<int>> tripletsVector(uniqueTriplets.begin(), uniqueTriplets.end());
        return tripletsVector;
    }
};
// [[-4, 0, 4],

// [1,2,3,4]
// -4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4

// -4
//                        .
//                                    .

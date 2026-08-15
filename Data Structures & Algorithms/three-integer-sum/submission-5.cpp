class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> uniqueNums;
        for (int i = 0; i < nums.size(); i++) {
            uniqueNums[nums[i]].push_back(i);
        }

        set<vector<int>> uniqueTriplets;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];

                auto it = uniqueNums.find(-sum);
                if (it != uniqueNums.end()) {
                    for (int id : it->second) {
                        if (id != i && id != j) {
                            vector<int> triplet{nums[i], nums[j], nums[id]};
                            sort(triplet.begin(), triplet.end());
                            uniqueTriplets.insert(std::move(triplet));
                            break;
                        }
                    }
                }

            }
        }

        vector<vector<int>> vectorTriplets(uniqueTriplets.begin(), uniqueTriplets.end());
        return vectorTriplets;
    }
};


// [-1,0,1,1,1,1,1,1,1,1,1]
// (-1, 0) = -1
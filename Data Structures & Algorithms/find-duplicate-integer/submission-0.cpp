class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        for (int num : nums) {
            if (visited[num - 1]) {
                return num;
            }

            visited[num - 1] = true;
        }

        return -1;
    }
};

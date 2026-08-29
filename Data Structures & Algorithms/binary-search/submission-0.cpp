class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                return middle;
            }
        }

        return -1;
    }
};


//  0 1 2 3 4 5
// -1 0 2 4 6 8
//      .
//            .

// 5 - 0 / 2 = 5/2 = 2
// 2 + (5-2)/2 = 3
class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            
            int mid = left + ((right - left) / 2);
            
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }

            if (nums[left] < nums[right]) {
                return nums[left];
            }
            
        }

        return nums[right];
    }
};


// 3,4,5,1,2
//       .
//     .
//         .

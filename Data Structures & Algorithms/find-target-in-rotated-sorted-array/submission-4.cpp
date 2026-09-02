class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[left] > nums[right]) {
            
            while (left < right) {
                int mid = left + ((right - left) / 2);
                if (nums[mid] > nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            int minIndex = left;
            if (target < nums[minIndex]) {
                return -1;
            }

            if (target < nums[nums.size() - 1]) {
                left = minIndex;
                right = nums.size() - 1;
            } else if (target > nums[nums.size() - 1]){
                left = 0;
                right = minIndex - 1;
            } else if (target == nums[nums.size() - 1]) {
                return nums.size() - 1; 
            }
        }

        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        return -1;
    }
};

// 3,4,5,6,1,2
// .
//     .
//         .
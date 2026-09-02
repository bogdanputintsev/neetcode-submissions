class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // Find index of minimum element.
        while (left < right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Target is smaller than the minimum.
        int minIndex = left;
        if (target < nums[minIndex]) {
            return -1;
        }

        // Determine which sorted half contains target.
        if (target <= nums.back()) {
            left = minIndex;
            right = nums.size() - 1;
        } else {
            left = 0;
            right = minIndex - 1;
        }

        // Normal binary search.
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

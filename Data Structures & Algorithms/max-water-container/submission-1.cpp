class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int result = 0;

        while (left < right) {
            int current = (right - left) * (min(heights[left], heights[right]));
            result = max(result, current);

            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }   

        return result;
    }
};

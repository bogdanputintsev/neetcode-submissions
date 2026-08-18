class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> result(height.size());

        int maxLeft = 0;
        for (int i = 1; i < height.size(); i++) {
            maxLeft = max(maxLeft, height[i - 1]);
            result[i] = maxLeft;
        }

        int maxRight = 0; 
        result[height.size() - 1] = 0;
        for (int i = height.size() - 2; i >= 0; i--) {
            maxRight = max(maxRight, height[i + 1]);
            result[i] = max(min(maxRight, result[i]) - height[i], 0);
        }

        return std::accumulate(result.begin(), result.end(), 0);
    }
};


// 0 0 2 2 3 3 3 3 3 3
// 3 3 3 3 3 3 3 2 1 0
// 0 0 2 2 3 3 3 2 1 0
// 0 0 2 0 2 3 2 0 0 0
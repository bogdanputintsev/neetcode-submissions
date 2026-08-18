class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> result(height.size());
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
    
        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }

        for (int i = height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        for (int i = 1; i < height.size(); i++) {
            result[i] = max(min(maxLeft[i], maxRight[i]) - height[i], 0);
        }

        return std::accumulate(result.begin(), result.end(), 0);
    }
};


// 0,2,0,3,1,0,1,3,2,1
// 0 0 2 2 3 3 3 3 3 3
// 3 3 3 3 3 3 3 2 1 0
// 0 0 2 2 3 3 3 2 1 0
// 0 0 2 0 2 3 2 0 0 0
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> indices;

        for (int i = 0; i <= heights.size(); i++) {
            int currentHeight = (i == heights.size()) ? 0 : heights[i];

            while (!indices.empty() && heights[indices.top()] >= currentHeight) {

                int height = heights[indices.top()];

                indices.pop();

                int width = indices.empty() 
                    ? i 
                    : (i - indices.top() - 1);

                maxArea = max(maxArea, width * height);
            }

            indices.push(i);
        }

        return maxArea;
    }
};


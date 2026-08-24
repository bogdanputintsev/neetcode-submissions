class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size());
        stack<int> indices;

        for (int i = 0; i < temperatures.size(); i++) {

            while (!indices.empty() && temperatures[indices.top()] < temperatures[i]) {
                int previousIndex = indices.top();
                indices.pop();

                results[previousIndex] = i - previousIndex;
            }
            
            indices.push(i);
        }

        return results;
    }
};
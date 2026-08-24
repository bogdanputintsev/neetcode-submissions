class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size());
        stack<int> indexes;

        indexes.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (!indexes.empty() && temperatures[indexes.top()] < temperatures[i]) {
                results[indexes.top()] = i - indexes.top();
                indexes.pop();
            }
            
            indexes.push(i);
        }

        return results;
    }
};
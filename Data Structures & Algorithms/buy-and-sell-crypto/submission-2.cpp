class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int maxRight = prices[prices.size() - 1];

        for (int i = prices.size() - 2; i >= 0; i--) {
            result = max(result, maxRight - prices[i]);
            maxRight = max(maxRight, prices[i]);
        }

        return result;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxRight(prices.size());
        for (int i = prices.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], prices[i + 1]);
        }

        int result = 0;

        for (int i = 0; i < prices.size(); i++) {   
            result = max(maxRight[i] - prices[i], result);
        }

        return result;
    }
};

// 10,1,5,6,7,1
//  7 7 7 7 1 0
//  0 6 2 1 0 0

// 1

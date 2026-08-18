class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int result = 0;
        int left = 0;
        int right = 1;

        while (left < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                result = max(result, prices[right] - prices[left]);
                right++;
            }

            if (right >= prices.size()) {
                break;
            }
        }

        return result;
    }
};



class Solution {
public:
    int maxValue(const vector<int>& piles) {
        int maxValue = 0;
        for (int pile : piles) {
            maxValue = max(maxValue, pile);
        }

        return maxValue;
    }

    int getHoursForAllPiles(const vector<int>& piles, int k) {
        int sum = 0;
        for (int pile : piles) {
            sum += ceil(static_cast<double>(pile) / k);
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // if (piles.size() == 1) {
        //     return ceil(static_cast<double>(piles[0]) / h);
        // }

        int lo = 1;
        int hi = maxValue(piles);
        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            int sum = getHoursForAllPiles(piles, mid);
            if (sum <= h) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};

// [10]
// 9

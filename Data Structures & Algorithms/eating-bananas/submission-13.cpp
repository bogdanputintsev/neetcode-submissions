class Solution {
public:
    int getHoursForAllPiles(const vector<int>& piles, int k) {
        int sum = 0;
        for (int pile : piles) {
            sum += ceil(static_cast<double>(pile) / k);
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        if (piles.size() == 1) {
            return ceil(static_cast<double>(piles[0]) / h);
        }

        int lo = 1;
        int hi = piles[piles.size() - 1];
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

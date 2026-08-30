class Solution {
public:
    int upperBound(const vector<vector<int>>& matrix, int target) {
        int lo = 0;
        int hi = matrix.size();

        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            if (matrix[mid][0] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = upperBound(matrix, target) - 1;
        if (row < 0) {
            return false;
        }
        
        int minColIdx = 0;
        int maxColIdx = matrix[0].size() - 1;
        while (minColIdx <= maxColIdx) {
            const int colIdx = minColIdx + ((maxColIdx - minColIdx) / 2);
            const int value = matrix[row][colIdx];
            if (value == target) {
                return true;
            } else if (value > target) {
                maxColIdx = colIdx - 1;
            } else if (value < target) {
                minColIdx = colIdx + 1;
            }
        }

        return false;
    }
};

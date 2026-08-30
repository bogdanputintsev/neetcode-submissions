class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowMin = 0;
        int rowMax = matrix.size() - 1;

        while (rowMin < rowMax) {
            int rowIndex = rowMin + (ceil((rowMax - rowMin) / 2.0f));
            if (rowIndex == rowMin) {
                break;
            }

            if (matrix[rowIndex][0] > target) {
                rowMax = rowIndex - 1;
            } else if (matrix[rowIndex][0] < target) {
                rowMin = rowIndex;
            } else {
                return true;
            }
        }

        int minColIdx = 0;
        int maxColIdx = matrix[0].size() - 1;
        while (minColIdx <= maxColIdx) {
            const int colIdx = minColIdx + ((maxColIdx - minColIdx) / 2);
            const int value = matrix[rowMin][colIdx];
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

// 13
// [1, 3]
//  .
//     .

// [[1], [3]]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }  

        auto it = std::upper_bound(
            matrix.begin(),
            matrix.end(),
            target,
            [](int target, const vector<int>& row) {
                return target < row[0];
            }
        );

        if (it == matrix.begin()) {
            return false;
        }

        *it--;
    
        return std::binary_search(it->begin(), it->end(), target);
    }
};

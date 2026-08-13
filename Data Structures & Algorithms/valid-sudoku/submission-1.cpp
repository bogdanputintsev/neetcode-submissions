class Solution {
private:
    static constexpr int SIZE = 9;
    static constexpr char EMPTY_CHAR = '.';

    array<unordered_set<int>, SIZE> rowsUnique;
    array<unordered_set<int>, SIZE> colsUnique;
    array<unordered_set<int>, SIZE> boxsUnique;

    optional<int> toInt(const char ch) {
        if (ch == EMPTY_CHAR) {
            return nullopt;
        }

        return ch - '0';
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                auto value = toInt(board[row][col]);
                if (!value.has_value()) {
                    continue;
                }

                const int box = floor(col / 3) + (floor(row / 3) * 3);

                if (rowsUnique[row].contains(*value)
                 || colsUnique[col].contains(*value)
                 || boxsUnique[box].contains(*value)) {
                    return false;
                 }

                rowsUnique[row].insert(*value);
                colsUnique[col].insert(*value);
                boxsUnique[box].insert(*value);
            }
        }

        return true;
    }
};




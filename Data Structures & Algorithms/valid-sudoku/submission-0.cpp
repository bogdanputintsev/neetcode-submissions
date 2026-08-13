class Solution {
private:
    static constexpr char EMPTY_CHAR = '.';
    static constexpr int SIZE = 9;

    optional<int> toInt(const char ch) {
        if (ch == EMPTY_CHAR) {
            return std::nullopt;
        }

        return ch - '0';
    }

public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            if (!rowIsValid(board, row)) {
                return false;
            }
        }

        for (int column = 0; column < 9; column++) {
            if (!columnIsValid(board, column)) {
                return false;
            }
        }

        for (int subbox = 0; subbox < 9; subbox++) {
            if (!subboxIsValid(board, subbox)) {
                return false;
            }
        }

        return true;
    }

    bool rowIsValid(const vector<vector<char>>& board, const int row) {
        std::array<bool, 10> numberExists{};

        for (int i = 0; i < 9; i++) {
            const auto value = toInt(board[row][i]);
            if (!value.has_value()) {
                continue;
            }

            if (numberExists[*value]) {
                return false;
            }

            numberExists[*value] = true;
        }

        return true;
    }

    bool columnIsValid(const vector<vector<char>>& board, const int column) {
        std::array<bool, 10> numberExists{};

        for (int i = 0; i < 9; i++) {
            const auto value = toInt(board[i][column]);
            if (!value.has_value()) {
                continue;
            }

            if (numberExists[*value]) {
                return false;
            }

            numberExists[*value] = true;
        }

        return true;
    }

    bool subboxIsValid(const vector<vector<char>>& board, const int subbox) {
        // 0 -> [[0, 0], [0, 1], [0, 2]],
        //      [[1, 0], [1, 1], [1, 2]]
        //      [[2, 0], [2, 1], [2, 2]]
        // 1 -> [[0, 3], [0, 3], [0, 3]],
        //      [[1, 4], [1, 4], [1, 4]]
        //      [[2, 5], [2, 5], [2, 5]]
        // 3 -> [[3, 0], [3, 1], [3, 2]],
        //      [[4, 0], [4, 1], [4, 2]]
        //      [[5, 0], [5, 1], [5, 2]]

        // S: 0 -> { R: 0, C: 0 }
        // S: 1 -> { R: 3, C: 0 }
        // S: 2 -> { R: 6, C: 0 }
        // S: 3 -> { R: 0, C: 3 }
        // S: 4 -> { R: 3, C: 3 }
        // S: 5 -> { R: 6, C: 3 }
        // S: 6 -> { R: 0, C: 6 }
        // S: 7 -> { R: 3, C: 6 }
        // S: 8 -> { R: 6, C: 6 }

        // R: ((S % 3) * 3)
        // C: floor(S / 3) * 3

        array<bool, 10> numberExists{};

        int rowStart = (subbox % 3) * 3;
        int colStart = floor(subbox / 3) * 3;

        for (int x = rowStart; x < rowStart + 3; x++) {
            for (int y = colStart; y < colStart + 3; y++) {
                const auto value = toInt(board[x][y]);
                if (!value.has_value()) {
                    continue;
                }
                if (numberExists[*value]) {
                    return false;
                }

                numberExists[*value] = true;
            }
        }

        return true;

        // 0 -> {0, 0}
    }
};

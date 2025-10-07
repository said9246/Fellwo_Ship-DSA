class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use sets to track numbers in rows, columns, and boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue; // skip empty cells

                int boxIndex = (i / 3) * 3 + (j / 3);

                // If number already exists in row, column, or box → invalid
                if (rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c))
                    return false;

                // Mark number as seen
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};

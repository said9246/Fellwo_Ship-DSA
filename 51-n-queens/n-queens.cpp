class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // check left diagonal
        for (int i = row-1, j = col-1; i>=0 && j>=0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // check right diagonal
        for (int i = row-1, j = col+1; i>=0 && j<n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtrack(vector<string>& board, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                backtrack(board, row+1, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return ans;
    }
};

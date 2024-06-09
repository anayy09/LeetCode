class Solution {
private:
    void placeQueens(int n, int row, vector<string> &board, vector<vector<string>> &result, vector<bool> &cols, vector<bool> &diags, vector<bool> &antiDiags) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int diagIdx = row - col + n - 1;
            int antiDiagIdx = row + col;
            if (cols[col] || diags[diagIdx] || antiDiags[antiDiagIdx]) continue;

            board[row][col] = 'Q';
            cols[col] = diags[diagIdx] = antiDiags[antiDiagIdx] = true;
            placeQueens(n, row + 1, board, result, cols, diags, antiDiags);
            board[row][col] = '.';
            cols[col] = diags[diagIdx] = antiDiags[antiDiagIdx] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diags(2 * n - 1, false);
        vector<bool> antiDiags(2 * n - 1, false);
        placeQueens(n, 0, board, result, cols, diags, antiDiags);
        return result;
    }
};

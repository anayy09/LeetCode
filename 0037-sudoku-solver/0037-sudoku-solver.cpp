class Solution {
private:
    bool isValid(vector<vector<char>>& brd, int r, int c, char dgt) {
        for (int i = 0; i < 9; ++i) {
            if (brd[r][i] == dgt || brd[i][c] == dgt || brd[r / 3 * 3 + i / 3][c / 3 * 3 + i % 3] == dgt) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& brd) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (brd[r][c] == '.') {
                    for (char dgt = '1'; dgt <= '9'; ++dgt) {
                        if (isValid(brd, r, c, dgt)) {
                            brd[r][c] = dgt;
                            if (solve(brd)) return true;
                            brd[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& brd) {
        solve(brd);
    }
};

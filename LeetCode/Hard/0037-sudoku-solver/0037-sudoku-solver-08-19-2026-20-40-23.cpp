class Solution {
public:
    bool isValid(int i, int j, int k, vector<vector<char>>& board) {
        for(int s = 0; s < 9; s++) {
            if(board[i][s] == k + '0') {
                return false;
            }
        };

        for(int s = 0; s < 9; s++) {
            if(board[s][j] == k + '0') {
                return false;
            }
        };

        int rowStart = (i / 3) * 3;
        int colStart = (j / 3) * 3;

        for (int r = rowStart; r < rowStart + 3; r++) {
            for (int c = colStart; c < colStart + 3; c++) {
                if (board[r][c] == k + '0') {
                    return false;
                }
            }
        }
        return true;

    };

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(int k = 1; k <= 9; k++) {
                        if(isValid(i,j, k, board)) {
                            board[i][j] = k + '0';
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
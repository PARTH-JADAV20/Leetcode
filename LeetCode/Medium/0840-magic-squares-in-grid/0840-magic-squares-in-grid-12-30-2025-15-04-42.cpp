class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j) {
        if (grid[i+1][j+1] != 5) return false;
        bool seen[10] = {false};
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                int val = grid[i+r][j+c];
                if (val < 1 || val > 9 || seen[val]) return false;
                seen[val] = true;
            }
        }

        for (int r = 0; r < 3; r++) {
            if (grid[i+r][j] + grid[i+r][j+1] + grid[i+r][j+2] != 15)
                return false;
        }

        for (int c = 0; c < 3; c++) {
            if (grid[i][j+c] + grid[i+1][j+c] + grid[i+2][j+c] != 15)
                return false;
        }

        if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15)
            return false;

        if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};

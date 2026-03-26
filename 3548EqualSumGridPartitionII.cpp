class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;

        for (auto &row : grid)
            for (auto val : row)
                total += val;

        for (int k = 0; k < 4; k++) {
            unordered_set<long long> exist;
            exist.insert(0);

            long long sum = 0;

            int m = grid.size();
            int n = grid[0].size();

            if (m < 2) {
                grid = rotation(grid);
                continue;
            }

            // Single column case
            if (n == 1) {
                for (int i = 0; i < m - 1; i++) {
                    sum += grid[i][0];
                    long long tag = 2 * sum - total;

                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0])
                        return true;
                }
                grid = rotation(grid);
                continue;
            }

            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }

                long long tag = 2 * sum - total;

                // First row (single row case)
                if (i == 0) {
                    if (tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1])
                        return true;
                    continue;
                }

                int upperRows = i + 1;
                int upperCols = n;

                // Proper 2D grid
                if (upperRows > 1 && upperCols > 1) {
                    if (exist.find(tag) != exist.end())
                        return true;
                }
            }

            grid = rotation(grid);
        }

        return false;
    }
};
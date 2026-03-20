class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                vector<int> kgrid;
                
                // Collect elements
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kgrid.push_back(grid[x][y]);
                    }
                }
                
                // Sort
                sort(kgrid.begin(), kgrid.end());
                
                int minDiff = INT_MAX;
                
                // Compute min difference (skip duplicates)
                for (int p = 1; p < kgrid.size(); p++) {
                    if (kgrid[p] != kgrid[p - 1]) {
                        minDiff = min(minDiff, kgrid[p] - kgrid[p - 1]);
                    }
                }
                
                // If all elements same
                ans[i][j] = (minDiff == INT_MAX) ? 0 : minDiff;
            }
        }
        
        return ans;
    }
};
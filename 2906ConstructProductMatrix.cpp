class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        int MOD = 12345;
        int n = grid.length, m = grid[0].length;
        int size = n * m;

        // Step 1: Flatten
        int[] arr = new int[size];
        int idx = 0;
        for (int[] row : grid) {
            for (int val : row) {
                arr[idx++] = val % MOD;
            }
        }

        // Step 2: Prefix
        int[] prefix = new int[size];
        prefix[0] = 1;
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }

        // Step 3: Suffix
        int[] suffix = new int[size];
        suffix[size - 1] = 1;
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        // Step 4: Result
        int[] resFlat = new int[size];
        for (int i = 0; i < size; i++) {
            resFlat[i] = (prefix[i] * suffix[i]) % MOD;
        }

        // Step 5: Convert back to 2D
        int[][] result = new int[n][m];
        idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = resFlat[idx++];
            }
        }

        return result;
    }
}
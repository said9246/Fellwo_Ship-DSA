class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return dp[i][j];

        int best = 1;
        for (auto &d : dirs) {
            int x = i + d[0];
            int y = j + d[1];
            
            if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j]) {
                best = max(best, 1 + dfs(x, y, matrix));
            }
        }

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;

        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};

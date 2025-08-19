class Solution {
public:
    int n, m;
    unordered_map<char, vector<int>> pos; 
    vector<vector<int>> dp;

    int solve(string &ring, string &key, int i, int j) {
        if (j == m) return 0; // sab characters print ho gaye

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k : pos[key[j]]) {
            // clockwise distance
            int diff = abs(i - k);
            int step = min(diff, n - diff); 
            ans = min(ans, step + 1 + solve(ring, key, k, j + 1));
        }
        return dp[i][j] = ans;
    }

    int findRotateSteps(string ring, string key) {
        n = ring.size();
        m = key.size();

        // har character ki positions store karo
        for (int i = 0; i < n; i++) {
            pos[ring[i]].push_back(i);
        }

        dp.assign(n, vector<int>(m, -1));

        return solve(ring, key, 0, 0);
    }
};

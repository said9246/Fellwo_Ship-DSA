class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1; // empty string
        dp[1] = 1; // first char valid (already checked it's not '0')

        for (int i = 2; i <= n; i++) {
            // single digit decode (must not be '0')
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            // two digit decode (must be between 10 and 26)
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

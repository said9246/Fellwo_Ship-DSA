class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Precompute powers of 2
        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long add = (nums[i] * pow2[i]) % MOD;             // as max
            long long sub = (nums[i] * pow2[n - i - 1]) % MOD;     // as min
            ans = (ans + add - sub + MOD) % MOD;
        }
        return ans;
    }
};

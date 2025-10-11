class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        
        // step 1: numbers array banao (1 to n)
        for(int i = 1; i <= n; i++) {
            numbers.push_back(i);
            fact *= i;
        }

        k--;  // 0-based indexing
        string ans = "";
        
        // step 2: har position pe correct digit choose karo
        for(int i = n; i >= 1; i--) {
            fact /= i;
            int index = k / fact;
            ans += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= fact;
        }

        return ans;
    }
};

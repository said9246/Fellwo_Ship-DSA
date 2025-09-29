class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;  
        vector<vector<int>> result;

        // Step 1: Reverse word map banana
        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        // Step 2: Har word ke liye check karna
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int n = word.size();

            // Split karke prefix + suffix palindromes check karna
            for (int cut = 0; cut <= n; cut++) {
                string left = word.substr(0, cut);
                string right = word.substr(cut);

                // Agar left palindrome hai → right ka reverse dhoondo
                if (isPalindrome(left)) {
                    if (mp.count(right) && mp[right] != i) {
                        result.push_back({mp[right], i});
                    }
                }

                // Agar right palindrome hai → left ka reverse dhoondo
                // (cut < n) taki duplicate avoid ho
                if (cut < n && isPalindrome(right)) {
                    if (mp.count(left) && mp[left] != i) {
                        result.push_back({i, mp[left]});
                    }
                }
            }
        }

        return result;
    }

private:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};

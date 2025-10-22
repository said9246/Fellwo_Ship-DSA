class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        vector<string> result;
        int n = s.size();

        if (n < 10) return result;

        for (int i = 0; i <= n - 10; i++) {
            string sub = s.substr(i, 10);
            seen[sub]++;
            if (seen[sub] == 2) result.push_back(sub); // add only once
        }
        return result;
    }
};

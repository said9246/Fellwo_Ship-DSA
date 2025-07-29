class Solution {
public:
    string makeGood(string s) {
        string result = "";
        for (char c : s) {
            if (!result.empty() && abs(result.back() - c) == 32) {
                result.pop_back(); // Remove the bad pair
            } else {
                result.push_back(c); // Add character to result
            }
        }
        return result;
    }
};

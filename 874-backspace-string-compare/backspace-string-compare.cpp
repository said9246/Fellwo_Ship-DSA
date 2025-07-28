class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getFinal(s) == getFinal(t);
    }

    string getFinal(string str) {
        string res;
        for (char c : str) {
            if (c == '#') {
                if (!res.empty()) res.pop_back();
            } else {
                res += c;
            }
        }
        return res;
    }
};

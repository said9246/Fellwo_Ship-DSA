class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;

        // First pass: mark invalid parentheses
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    s[i] = '*'; // mark invalid ')'
                }
            }
        }

        // Mark remaining unmatched '('
        while (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }

        // Second pass: build result without '*'
        string result;
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }

        return result;
    }
};

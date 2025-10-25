#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        int num = 0;
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } 
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } 
            else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= st.top();  // pop sign
                st.pop();
                result += st.top();  // pop previous result
                st.pop();
            }
        }

        // Add the last number
        result += sign * num;
        return result;
    }
};

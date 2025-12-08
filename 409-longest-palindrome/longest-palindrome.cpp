class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);

        // Count frequency of each character
        for(char c : s) freq[c]++;

        int length = 0;
        bool oddFound = false;

        for(int f : freq) {
            if(f % 2 == 0) length += f;          // even count → fully added
            else {
                length += f - 1;                 // add even part
                oddFound = true;                 // we can put 1 odd character in center
            }
        }

        return oddFound ? length + 1 : length;
    }
};

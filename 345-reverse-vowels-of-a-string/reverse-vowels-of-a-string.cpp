class Solution {
public:
    string reverseVowels(string s) {
        int i=0; int j=s.size();
          string v = "aeiouAEIOU";
        while(i<j){
            
            while(i<j && v.find(s[i]) == -1) i++;
            while(i<j && v.find(s[j])== -1) j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};
class Solution {
public:
    bool checkIfPangram(string sentence) {

        unordered_set <char> leters;

        for(char c: sentence){
            leters.insert(c);
        }

        return leters.size()==26;
        
    }
};
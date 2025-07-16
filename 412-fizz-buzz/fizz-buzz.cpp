class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for(int i = 1; i <= n; i++) {  // Fix: Loop runs till n (i <= n)
            if(i % 3 == 0 && i % 5 == 0) {
                result.push_back("FizzBuzz");  // Fix: First check for "FizzBuzz"
            } else if(i % 3 == 0) {
                result.push_back("Fizz");  
            } else if(i % 5 == 0) {
                result.push_back("Buzz");  
            } else {
                result.push_back(to_string(i));  
            }
        }
        
        return result;
    }
};

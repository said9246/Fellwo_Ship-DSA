class Solution {
public:
    void reverseString(vector<char>& s) {
        //    reverse(s.begin(),s.end());    // this is one method and other is following 

        
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            char temp = s[left];  // Store left character
            s[left] = s[right];   // Assign right character to left position
            s[right] = temp;      // Assign stored character to right position
            
            left++;   // Move left pointer forward
            right--;  // Move right pointer backward
        }
    }
};

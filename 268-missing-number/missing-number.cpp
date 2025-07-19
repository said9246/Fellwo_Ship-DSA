class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> table;

        for (int num : nums) {
            table.insert(num); 
        }

        for (int i = 0; i <= nums.size(); i++) {
            if (table.find(i) == table.end()) {
                return i;
            }
        }

        return -1; 
    }
};

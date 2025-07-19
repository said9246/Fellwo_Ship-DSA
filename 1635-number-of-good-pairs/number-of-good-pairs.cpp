class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> ans;
        int count = 0;

        for (int num : nums) {
            count += ans[num];  
            ans[num]++;         
        }

        return count;
    }
};
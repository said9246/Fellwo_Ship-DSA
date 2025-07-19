class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];

            if (mp.count(difference)) {
                return {mp[difference], i};
            } else {
                mp[nums[i]] = i;
            }
        }

        return {}; 
    }
};

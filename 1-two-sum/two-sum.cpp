class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value → index
        
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            // If "need" already exists, return their indices
            if (mp.count(need)) {
                return {mp[need], i};
            }

            // Store current number with its index
            mp[nums[i]] = i;
        }

        return {}; // no answer case
    }
};

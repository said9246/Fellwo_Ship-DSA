class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        backtrack(nums, used, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& used, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip already used numbers
            if (used[i]) continue;
            
            // Skip duplicates: if same number and previous not used, skip
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            
            used[i] = true;
            current.push_back(nums[i]);
            
            backtrack(nums, used, current, result);
            
            // backtrack (undo)
            used[i] = false;
            current.pop_back();
        }
    }
};

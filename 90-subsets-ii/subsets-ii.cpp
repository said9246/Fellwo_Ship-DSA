class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;  // To store all unique subsets
        vector<int> currentSubset;    // To store the current subset being explored
        sort(nums.begin(), nums.end());  // Sort the array to easily skip duplicates
        backtrack(nums, 0, currentSubset, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);  // Add the current subset to the result
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates: If the current number is the same as the previous number, skip it
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push_back(nums[i]);  // Add the current number to the subset
            backtrack(nums, i + 1, currentSubset, result);  // Recursively explore further
            currentSubset.pop_back();  // Remove the current number to explore other possibilities
        }
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        // Mark the numbers that appear by making the index negative
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }

        // Collect numbers whose indices are still positive (not appeared)
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                result.push_back(i + 1);
        }

        return result;
    }
};

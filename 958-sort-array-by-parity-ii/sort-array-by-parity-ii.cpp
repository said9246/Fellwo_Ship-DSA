class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2;
            } else if (nums[j] % 2 == 1) {
                j += 2;
            } else {
                // both nums[i] is odd and nums[j] is even → swap
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};

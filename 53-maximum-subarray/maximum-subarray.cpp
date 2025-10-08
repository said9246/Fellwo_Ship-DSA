class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Agar currentSum negative ho gaya to new start lo
            currentSum = max(nums[i], currentSum + nums[i]);
            // Maximum sum update karo
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find median
        auto midIt = nums.begin() + n / 2;
        nth_element(nums.begin(), midIt, nums.end());
        int median = *midIt;

        // Virtual index mapping
        auto index = [&](int i) { return (1 + 2 * i) % (n | 1); };

        // Step 2: 3-way partition (Dutch National Flag)
        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (nums[index(i)] > median) {
                swap(nums[index(left)], nums[index(i)]);
                left++, i++;
            } else if (nums[index(i)] < median) {
                swap(nums[index(right)], nums[index(i)]);
                right--;
            } else {
                i++;
            }
        }
    }
};

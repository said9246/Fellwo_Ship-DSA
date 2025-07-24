class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end()); // sort by value

        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int sum = arr[start].first + arr[end].first;
            if (sum == target) {
                return {arr[start].second, arr[end].second}; // return original indices
            }
            else if (sum < target) {
                start++;
            }
            else {
                end--;
            }
        }

        return {}; // no answer found
    }
};


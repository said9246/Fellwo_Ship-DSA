#include <set>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; // to handle large values safely

        for (int i = 0; i < nums.size(); i++) {
            long long num = nums[i];

            // Find the smallest element >= num - valueDiff
            auto it = window.lower_bound(num - valueDiff);

            // Check if that element is within valueDiff range
            if (it != window.end() && abs(*it - num) <= valueDiff)
                return true;

            // Insert current number into window
            window.insert(num);

            // Maintain window size (indexDiff)
            if (window.size() > indexDiff)
                window.erase(nums[i - indexDiff]);
        }

        return false;
    }
};

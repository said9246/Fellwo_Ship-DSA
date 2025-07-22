class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Put all frequencies into a set
        unordered_set<int> seen;
        for (auto pair : freq) {
            if (seen.count(pair.second)) {
                return false; // Duplicate frequency found
            }
            seen.insert(pair.second);
        }

        return true; // All frequencies are unique
    }
};

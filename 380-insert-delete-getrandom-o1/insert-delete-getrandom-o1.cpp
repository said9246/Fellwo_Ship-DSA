class RandomizedSet {
    unordered_map<int, int> mp; // val -> index in nums
    vector<int> nums;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int last = nums.back();
        int idx = mp[val];
        nums[idx] = last;
        mp[last] = idx;
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        return nums[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

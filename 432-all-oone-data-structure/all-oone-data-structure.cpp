class AllOne {
private:
    unordered_map<string, int> keyCount; // key -> count
    map<int, unordered_set<string>> countKeys; // count -> all keys with that count

public:
    AllOne() {}

    void inc(string key) {
        int count = keyCount[key]++;
        if (count > 0) {
            countKeys[count].erase(key);
            if (countKeys[count].empty()) countKeys.erase(count);
        }
        countKeys[count + 1].insert(key);
    }

    void dec(string key) {
        if (keyCount.find(key) == keyCount.end()) return;
        int count = keyCount[key]--;
        countKeys[count].erase(key);
        if (countKeys[count].empty()) countKeys.erase(count);

        if (count - 1 == 0) {
            keyCount.erase(key);
        } else {
            countKeys[count - 1].insert(key);
        }
    }

    string getMaxKey() {
        if (countKeys.empty()) return "";
        return *countKeys.rbegin()->second.begin();
    }

    string getMinKey() {
        if (countKeys.empty()) return "";
        return *countKeys.begin()->second.begin();
    }
};

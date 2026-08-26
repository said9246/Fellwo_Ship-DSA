class LRUCache {
public:
    int capacity;

    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];

        int value = it->second;

        // Recently used → front
        lru.erase(it);
        lru.push_front({key, value});

        mp[key] = lru.begin();

        return value;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            lru.erase(mp[key]);
        }

        // Add new/recent key at front
        lru.push_front({key, value});
        mp[key] = lru.begin();

        // Capacity exceed
        if (lru.size() > capacity) {
            auto last = lru.back();

            mp.erase(last.first);
            lru.pop_back();
        }
    }
};
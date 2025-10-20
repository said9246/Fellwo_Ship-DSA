#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key -> iterator in list

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1; // not found
        
        // move accessed item to front (most recently used)
        cache.splice(cache.begin(), cache, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // update existing key
            mp[key]->second = value;
            cache.splice(cache.begin(), cache, mp[key]);
            return;
        }
        
        if (cache.size() == capacity) {
            // remove least recently used
            int oldKey = cache.back().first;
            cache.pop_back();
            mp.erase(oldKey);
        }
        
        // insert new key-value
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

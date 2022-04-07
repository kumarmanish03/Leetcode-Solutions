// Manish Kumar, IIIT Allahabad
// Medium

https://leetcode.com/problems/lru-cache/

class LRUCache {
    // {key, value}
    list<pair<int, int>> cache;
    // m[key] = key address in list
    unordered_map<int, list<pair<int, int>>::iterator> m;
    
    int capacity;
    
    void refreshPosition(int key, int value){
        cache.erase(m[key]);
        cache.push_front({key, value});
        m[key] = cache.begin();
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            refreshPosition(key, (*m[key]).second);
            return (*m[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            refreshPosition(key, value);
            return;
        }
        cache.push_front({key, value});
        m[key] = cache.begin();
        if(m.size() > this->capacity){
            int key = cache.back().first;
            cache.pop_back();
            m.erase(key);
        }
    }
};
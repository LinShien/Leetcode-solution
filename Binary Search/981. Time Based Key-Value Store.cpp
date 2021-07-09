class TimeMap {
public:
    /** Initialize your data structure here. */
    // HashTable + TreeMap(red black tree(binary search tree))
    TimeMap() {
        
    }
    
    // Time: O(1)
    void set(string key, string value, int timestamp) { 
        _set[key].emplace(timestamp, std::move(value));
    }
    
    // Time: O(logn)
    string get(string key, int timestamp) {
        auto pair_iter = _set.find(key);   // O(1), hashing
        
        if (pair_iter == _set.end()) {
            return "";
        }
        
        auto iter = pair_iter->second.upper_bound(timestamp);   // binary search O(logn)
        
        if (iter == pair_iter->second.begin()) {    // all timestamps are greater than this given timestamp
            return "";
        }
        
        return prev(iter)->second;
    }
    
private:
    unordered_map<string, map<int, string>> _set;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
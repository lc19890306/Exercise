class LRUCache{
public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    
    int get(int key) {
        auto it(cache.find(key));
        if (it == cache.end())
            return -1;
        history.splice(history.begin(), history, it->second); // move the target key-value pair to the front of the list
        return it->second->second;
    }
    
    void set(int key, int value) {
        auto it(cache.find(key));
        if (it != cache.end()) {
            history.splice(history.begin(), history, it->second); // move the target key-value pair to the front of the list
            it->second->second = value;
            return;
        }
        if (cache.size() == m_capacity) {
            auto key_to_be_deleted = history.back().first; // find the least used key-value pair on the list, namely, the last one
            history.pop_back();				   // pop the last one which is used least
            cache.erase(key_to_be_deleted);		   // erase the element least used from the cache
        }
        history.emplace_front(key, value); // add newly added key-value pair to the front of the list
        cache[key] = history.begin();	   // set current key point to the iterator to the newly added key-value pair on the list
    }
    
private:
    unordered_map<int, list<pair<int, int> >::iterator> cache; // maintain all keys mapping to the iterator to the key-value pairs on the list
    list<pair<int, int> > history; // maintain a list of key-value pairs with the LRU order
    size_t m_capacity;
};

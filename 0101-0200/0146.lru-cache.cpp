class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) {
    }
    
    int get(int key) {
        auto p = ma.find(key);
        if (p == ma.end()) return -1;
        int val = (p->second)->second;
        li.erase(p->second);
        li.push_back({key, val});
        ma[key] = --li.end();
        return val;
    }
    
    void put(int key, int value) {
        auto p = ma.find(key);
        if (p != ma.end()) li.erase(p->second);
        li.push_back({key, value});
        ma[key] = --li.end();
        if (li.size() > cap_) {
            auto pv = li.front();
            ma.erase(pv.first);
            li.pop_front();
        }
    }
private:
    int cap_;
    list<pair<int, int> > li;
    unordered_map<int, list<pair<int, int> >::iterator> ma;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

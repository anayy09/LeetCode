
class LRUCache {
public:
    LRUCache(int cap) : maxCap(cap) {}

    int get(int k) {
        if (umap.find(k) == umap.end()) return -1;
        cacheList.splice(cacheList.begin(), cacheList, umap[k]);
        return umap[k]->second;
    }
    
    void put(int k, int v) {
        if (umap.find(k) != umap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, umap[k]);
            umap[k]->second = v;
            return;
        }
        
        if (cacheList.size() == maxCap) {
            int oldKey = cacheList.back().first;
            cacheList.pop_back();
            umap.erase(oldKey);
        }
        
        cacheList.push_front({k, v});
        umap[k] = cacheList.begin();
    }

private:
    int maxCap;
    std::list<std::pair<int, int>> cacheList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> umap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
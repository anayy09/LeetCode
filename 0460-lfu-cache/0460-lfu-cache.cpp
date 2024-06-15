class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}
    
    int get(int key) {
        if (cap == 0 || keyValueMap.find(key) == keyValueMap.end()) return -1;
        
        updateFrequency(key);
        return keyValueMap[key].first;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        
        if (keyValueMap.find(key) != keyValueMap.end()) {
            keyValueMap[key].first = value;
            updateFrequency(key);
        } else {
            if (keyValueMap.size() == cap) {
                evict();
            }
            keyValueMap[key] = {value, 1};
            frequencyMap[1].push_front(key);
            keyIteratorMap[key] = frequencyMap[1].begin();
            minFreq = 1;
        }
    }

private:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> keyValueMap;
    unordered_map<int, list<int>> frequencyMap;
    unordered_map<int, list<int>::iterator> keyIteratorMap;

    void updateFrequency(int key) {
        int freq = keyValueMap[key].second;
        frequencyMap[freq].erase(keyIteratorMap[key]);
        
        if (frequencyMap[freq].empty() && freq == minFreq) {
            minFreq++;
        }
        
        keyValueMap[key].second++;
        frequencyMap[freq + 1].push_front(key);
        keyIteratorMap[key] = frequencyMap[freq + 1].begin();
    }
    
    void evict() {
        int keyToEvict = frequencyMap[minFreq].back();
        frequencyMap[minFreq].pop_back();
        
        if (frequencyMap[minFreq].empty()) {
            frequencyMap.erase(minFreq);
        }
        
        keyValueMap.erase(keyToEvict);
        keyIteratorMap.erase(keyToEvict);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

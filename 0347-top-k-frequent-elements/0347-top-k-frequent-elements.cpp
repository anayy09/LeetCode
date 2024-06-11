class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        priority_queue<pair<int, int>> maxHeap;
        
        for (auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return res;
    }
};

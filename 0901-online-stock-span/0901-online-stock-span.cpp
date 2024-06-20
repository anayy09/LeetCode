class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    vector<int> prices;
    stack<int> idxStack;
    
    int next(int price) {
        prices.push_back(price);
        int currentDay = prices.size() - 1;
        
        while (!idxStack.empty() && prices[idxStack.top()] <= price) {
            idxStack.pop();
        }
        
        int span = idxStack.empty() ? currentDay + 1 : currentDay - idxStack.top();
        idxStack.push(currentDay);
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
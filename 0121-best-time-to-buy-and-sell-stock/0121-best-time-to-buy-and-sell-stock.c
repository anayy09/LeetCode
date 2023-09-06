int maxProfit(int* prices, int pricesSize) {
    int min_price = prices[0];
    int profit = 0;
    int i;
    for (i = 0; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        if (prices[i] - min_price > profit) {
            profit = prices[i] - min_price;
        }
    }
    return profit;  
}

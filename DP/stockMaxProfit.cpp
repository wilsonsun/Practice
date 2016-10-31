    int maxProfit(vector<int>& prices) {
        int len = (int)prices.size();
        if (len <= 1)
            return 0;
        int min = prices[0];
        int profit = prices[1]-prices[0];
        
        for (int i = 2; i < len; ++i) {
            if (prices[i-1] < min) {
                min = prices[i-1];
            }
            profit = max(profit, prices[i] - min);
        }
        
        
        return profit<=0?0:profit;
    }

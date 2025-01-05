class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Greedy Algorithm
        // At every oportunity we want to take profit. So if the price is higher on the next day, then
        // purchase and make the trade
        
        // Iterate over the prices 0->n-1
        // If the price[i] < price[i+1] then make the trade
        int max_profit = 0;

        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i+1] > prices[i]) {
                max_profit += prices[i+1] - prices[i];
            }
        }

        return max_profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We cannot sell before we buy
        
        // Naive O(n2)
        // Loop through 0 - (n-1) days
        // loop through i+1 - n days taking the difference and storing the max difference
        // We do NOT need to track the days this happened on

        int max_profit = 0;
        // Time: O(n-1)
        for (int i = 0; i < prices.size() - 1; ++i) {
            // Time: O(n-2)
            for (int j = i + 1; j < prices.size(); ++j) {
                max_profit = std::max(max_profit, (prices[j] - prices[i]));
            }
        }

        return max_profit;

        // Total Space Complexity: O(1)
        // Total Time Complexity: O(n)*O(n) = O(n^2)
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We cannot sell before we buy

        // We iterate through the array of prices keeping track of the max profit and lowest
        // buying price. When we calculate a new max profit, store the profit (current min - pos).
        // When we come across a new min, store the min

        int max_profit = 0;
        int current_min = !prices.empty()? prices.front() : -1;

        // Time: O(n)
        for (int i = 1; i < prices.size(); ++i) {
            max_profit = std::max(max_profit, prices[i] - current_min);
            current_min = std::min(current_min, prices[i]);
        }

        return max_profit;

        // Total Space Complexity: O(1)
        // Total Time Complexity: O(n)
    }
};
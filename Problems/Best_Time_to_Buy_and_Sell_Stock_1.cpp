class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            // Update min_price if the current price is lower
            min_price = min(min_price, price);

            // Calculate profit if selling at current price
            int profit = price - min_price;

            // Update max_profit if the current profit is higher
            max_profit = max(max_profit, profit);
        }

        return max_profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices.at(0);
        int max_profit = 0;
        for(size_t i{1}; i < prices.size();i++){
            if(prices.at(i) < lowest){
                lowest = prices.at(i);
            }
            max_profit = max(max_profit, prices.at(i) - lowest);
        }
        return max_profit;
    }
};
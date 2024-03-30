class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int n = prices.size();
        
//         skipped i = 0 bcoz it will matter if i buy a stock on day 1 and sell on the day1 itself
        for(int i=1; i<n; i++){
            if(prices[i] > prices[i-1]){
                maximumProfit = maximumProfit + (prices[i] - prices[i-1]);
            }
        }
        return maximumProfit;
    }
};
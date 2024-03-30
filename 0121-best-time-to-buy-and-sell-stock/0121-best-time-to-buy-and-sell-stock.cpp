class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lowestPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int i=0; i<n; i++){
            lowestPrice = min(lowestPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - lowestPrice);
        }
        return maxProfit;
    }
};
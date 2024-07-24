class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = prices[0];
        int maxpro = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<minbuy)
                minbuy = prices[i];
            if(prices[i]-minbuy<=0)
                continue;
            maxpro = max(maxpro,prices[i]-minbuy);
        }
        return maxpro;
    }
};

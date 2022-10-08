class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = INT_MAX, maxProfit = 0;
        for( int i = 0; i < prices.size(); i++)
        {
            maxProfit = max( maxProfit, prices[i] - minTillNow);
            minTillNow = min( minTillNow, prices[i]);
        }
        return maxProfit;
    }
};
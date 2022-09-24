class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp[n+2];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 0;
        for( int i = 3; i <= n+1; i++)
        {
            dp[i] = min( dp[i-1] + cost[i-2], dp[i-2] + cost[i-3]);
        }
        return dp[n+1];
    }
};
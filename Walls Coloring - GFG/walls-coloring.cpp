//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int helper(int i,int flag, int N, vector<vector<int>> &dp, vector<vector<int>> &colors)
    {
        if( i >= N ) return 0;
        if( dp[i][flag] != -1 ) return dp[i][flag];
        if( flag == 0 )
        {
            return dp[i][flag] = min( colors[i][1] + helper(i+1,1,N,dp,colors), colors[i][2] + helper(i+1,2,N,dp,colors) );
        }
        if( flag == 1 )
        {
            return dp[i][flag] = min( colors[i][2] + helper(i+1,2,N,dp,colors), colors[i][0] + helper(i+1,0,N,dp,colors) );
        }
        if( flag == 2 )
        {
            return dp[i][flag] = min( colors[i][0] + helper(i+1,0,N,dp,colors), colors[i][1] + helper(i+1,1,N,dp,colors) );
        }
    }

    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int ans = INT_MAX;
        vector<vector<int>> dp(N,vector<int> (3,-1));
        dp[0][0] = colors[0][0];
        dp[0][1] = colors[0][1];
        dp[0][2] = colors[0][2];
        for( int x = 0; x < 3; x++)
        {
            ans = min(ans, colors[0][x] + helper(1,x,N,dp,colors));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
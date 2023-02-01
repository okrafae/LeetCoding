//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    long long int helper( int i, int N, int flag, int r[], int g[], int b[], vector<vector<long long int>> &dp)
    {
        if( i == N ) return 0;
        
        if( dp[i][flag] != -1 ) return dp[i][flag];
        
        
        if( flag == 0 )
        {
            return dp[i][flag] = min( g[i] + helper(i+1, N, 1, r, g, b, dp), b[i] + helper(i+1, N, 2, r, g, b, dp)); 
        }
        else if( flag == 1 )
        {
            return dp[i][flag] = min( b[i] + helper(i+1, N, 2, r, g, b, dp), r[i] + helper(i+1, N, 0, r, g, b, dp)); 
        }
        else if( flag == 2 )
        {
            return dp[i][flag] = min( r[i] + helper(i+1, N, 0, r, g, b, dp), g[i] + helper(i+1, N, 1, r, g, b, dp)); 
        }
    }

    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here
        vector<vector<long long int>> dp( N, vector<long long int> (3,-1));
        return min( { helper( 0, N, 0, r, g, b, dp) , helper( 0, N, 1, r, g, b, dp) , helper( 0, N, 2, r, g, b, dp) } );
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
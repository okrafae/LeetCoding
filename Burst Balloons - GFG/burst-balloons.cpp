//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    int helper( int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if( i > j ) return 0;
        if( dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for( int ind = i; ind <= j; ind++)
        {
            int cost = arr[i-1] * arr[ind] * arr[j+1] + helper( i, ind - 1, arr, dp) + helper( ind + 1, j, arr, dp);
            maxi = max( maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>> dp( N+1, vector<int> (N+1, -1));
        return helper( 1, N, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
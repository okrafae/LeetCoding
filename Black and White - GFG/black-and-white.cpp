//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

long long int mul(long long int a,long long int b)
{
    if( b == 1) return a%1000000007;
    long long int ans = mul( a,b/2);
    if( b%2 == 0)
        return ((ans%1000000007) + (ans%1000000007))%1000000007;
    else
        return (((ans%1000000007) + (ans%1000000007)) + a)%1000000007;

}

long long numOfWays(int N, int M)
{
    // write code here
    
    unsigned long long int totalWays = mul(N*M, (N*M) - 1)%1000000007;
    int dir[8][2] = { {2,1},{1,2},{-2,1},{-1,2},{2,-1},{1,-2},{-2,-1},{-1,-2} };
    int count = 0;
    for( int i = 0; i < N; i++)
    {
        for( int j = 0; j < M; j++)
        {
            for( int k = 0; k < 8; k++)
            {
                if( i + dir[k][0] >= 0 && i + dir[k][0] < N && j + dir[k][1] >=0 && j + dir[k][1] < M)
                {
                    count++;
                }
            }
        }
    }
    return (totalWays - count)%1000000007;
}
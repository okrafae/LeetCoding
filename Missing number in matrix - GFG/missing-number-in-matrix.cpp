//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        vector<long long int> rowSum(n,0),colSum(n,0);
        for( int i = 0; i < n; i++)
        {
            for( int j = 0; j < n; j++)
            {
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }
        long long int mini = LLONG_MAX, maxi = LLONG_MIN;
        for( int i = 0; i < n; i++)
        {
            mini = min( {mini, rowSum[i], colSum[i]});
            maxi = max( {maxi, rowSum[i], colSum[i]});
        }
        if( maxi - mini <= 0 ) return -1;
        long long int sum, d1 = 0, d2= 0;
        for( int i = 0; i < n; i++)
        {
            rowSum[i] = 0;
            colSum[i] = 0;
        }
        for( int i = 0; i < n; i++)
        {
            for( int j = 0; j < n; j++)
            {
                if( matrix[i][j] != 0)
                {
                    if( i == j) d1 += matrix[i][j];
                    if( i + j == n - 1) d2 += matrix[i][j];
                    rowSum[i] += matrix[i][j];
                    colSum[j] += matrix[i][j];
                }
                else
                {
                    if( i == j) d1 += maxi - mini;
                    if( i + j == n - 1) d2 += maxi - mini;
                    rowSum[i] += maxi - mini;
                    colSum[j] += maxi - mini;
                }
            }
        }
        if( d1 != d2 ) return -1;
        else 
        {
            sum = d1;
            for( int i = 0; i < n; i++)
            {
                if( sum != rowSum[i] || sum != colSum[i]) return -1;
            }
        }
        return maxi - mini;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans(2);
        ans[0] = 0;
        ans[1] = 0;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            count = 0;
            for( int j = 0; j < m; j++)
            {
                if( mat[i][j] == 1 ) count++;
            }
            if( count > ans[1] )
            {
                ans[1] = count;
                ans[0] = i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
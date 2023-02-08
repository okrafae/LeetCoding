//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long long int totalCells = n*n;
      vector<bool> rowFilled(n,false),columnFilled(n,false);
      vector<long long int> ans(k);
      int filledRowCount = 0, filledColCount = 0;
      for( int i = 0; i < k; i++)
      {
          int row = arr[i][0] - 1, col = arr[i][1] - 1;
          if( !rowFilled[row] )
          {
              rowFilled[row] = true;
              totalCells -= ( n - filledColCount  );
              filledRowCount++;
          }
          if( !columnFilled[col])
          {
              columnFilled[col] = true;
              totalCells -= ( n - filledRowCount );
              filledColCount++;
          }
          ans[i] = totalCells;
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
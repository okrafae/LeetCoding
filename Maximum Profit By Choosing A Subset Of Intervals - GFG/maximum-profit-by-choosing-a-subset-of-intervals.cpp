//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  static bool cmp( vector<int> &a, vector<int> &b)
  {
      if( a[1] == b[1] ) return a[0] <= b[0] ;
      return a[1] < b[1];
  }
  
  int binarySearch( int len, int key, vector<vector<int>> &intervals)
  {
      int low = 0, high = len, mid, index = -1;
      while( low <= high )
      {
          mid = low + (high - low)/2;
          if( intervals[mid][1] <= key )
          {
              index = mid;
              low = mid+1;
          }
          else
          {
              high = mid - 1;
          }
      }
      return index;
  }
  
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        vector<int> ans(n,0);
        sort( intervals.begin(), intervals.end(), cmp);
        ans[0] = intervals[0][2];
        for( int i = 1; i < n; i++)
        {
            int index = binarySearch( i-1, intervals[i][0], intervals);
            if( index == -1 )
            {
                ans[i] = intervals[i][2];
            }
            else
            {
                ans[i] = ans[index] + intervals[i][2];
            }
            ans[i] = max( ans[i-1], ans[i]);
        }
        return ans[n-1];
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
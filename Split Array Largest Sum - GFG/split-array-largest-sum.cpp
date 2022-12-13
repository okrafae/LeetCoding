//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  bool validSplit( int maxSum, int arr[], int N, int K, int totalSum)
  {
      if( K == 1 ) return totalSum <= maxSum;
      int sum = 0;
      for( int i = 0; i < N ; i++)
      {
          if( sum + arr[i] > maxSum)
          {
              sum = arr[i];
              K--;
              if( K < 1)  return false;
          }
          else if( sum + arr[i] == maxSum && i != N-1)
          {
              sum = 0;
              K--;
              if( K < 1) return false;
          }
          else
          {
              sum += arr[i];
          }
      }
      if( K < 1 ) return false;
      return true;
  }
  
  
    int splitArray(int arr[] ,int N, int K) {
        // code here
        
        int maxElement = 0, totalSum = 0;
        for( int i = 0; i < N; i++)
        {
            maxElement = max( maxElement, arr[i]);
            totalSum += arr[i];
        }
        int low = maxElement;
        int high = totalSum;
        int ans = -1;
        while( low <= high )
        {
            int mid = low + ( high - low)/2;
            if( validSplit( mid, arr, N , K , totalSum) )
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
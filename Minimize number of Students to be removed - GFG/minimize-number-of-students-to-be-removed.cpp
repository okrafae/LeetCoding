//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  int LIS(int H[],int N){
        vector<int>arr;
        arr.push_back(H[0]);
        for(int i=1;i<N;i++){
            if(H[i]>arr.back()) arr.push_back(H[i]);
            else{
             int ind = lower_bound(arr.begin(),arr.end(),H[i])-arr.begin();
             arr[ind] = H[i];
            }
        }
        return arr.size();
    }
  
    int removeStudents(int H[], int N) {
        // code here
         int len = LIS(H,N);
        return N-len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
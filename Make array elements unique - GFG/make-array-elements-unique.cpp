//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        unordered_map<int,int> m;
        long long int no_of_operations = 0;
        for( int i = 0; i < N; i++)
        {
            int currValue = arr[i]; 
            while( m[currValue] != 0 )
            {
                currValue++;
                no_of_operations++;
            }
            m[currValue] = 1;
        }
        return no_of_operations;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends
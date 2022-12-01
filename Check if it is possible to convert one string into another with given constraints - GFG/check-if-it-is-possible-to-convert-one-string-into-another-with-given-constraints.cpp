//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        int i = 0, j = 0;
        while( i < M && j < N )
        {
            while( i < M && S[i] == '#' ) i++;
            while( j < N && T[j] == '#' ) j++;

            if( S[i] != T[j] ) return 0;
            else
            {
                i++;
                j++;
            }
        }
        while( i < M )
        {
            if( S[i] == '#' ) i++;
            else return 0;
        }
        while( j < N )
        {
            if( T[j] == '#' ) j++;
            else return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends
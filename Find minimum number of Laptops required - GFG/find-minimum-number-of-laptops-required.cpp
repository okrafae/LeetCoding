//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
      public:
    static bool cmp( int a, int b)
    {
        if( abs(a) == abs(b) ) return a < b;
        return abs(a) < abs(b);
    }
    

    int minLaptops(int N, int start[], int end[]) {
        // Code here
        for(int i = 0; i < N; i++)
        {
            end[i] *= -1;
        }
        vector<int> v;
        for( int i = 0; i < N; i++)
        {
            v.push_back(start[i]);
            v.push_back(end[i]);
        }
        sort(v.begin(),v.end(),cmp);
        int maxLap = 0, currLap = 0;

        for(int i = 0; i < 2*N; i++)
        {
            if( v[i] > 0) currLap++;
            else currLap--;
            maxLap = max( maxLap, currLap);
        }
        return maxLap;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends
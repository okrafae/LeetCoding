//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPossible(long long int mid, int k, int n, vector<int> &stalls)
    {
        int count = 1;
        int prevStall = 0;
        for( int i = 1; i < n; i++)
        {
            if( stalls[i] - stalls[prevStall] >= mid)
            {
                prevStall = i;
                count++;
            }
            if( count == k ) return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        long long int low = 0, high = stalls[n-1], prevLow = 0;
        while( low <= high )
        {
            long long int mid = low + ( high - low)/2;
            if( isPossible(mid,k,n,stalls) )
            {
                prevLow = mid;
                low = mid+1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return prevLow;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
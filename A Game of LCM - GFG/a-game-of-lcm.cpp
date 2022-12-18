//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    long long int gcd(long long int a,long long int b)
    {
        if( b == 0) return a;
        return gcd( b, a%b );
    }
  public:
    long long maxGcd(int N) {
        // code here
        long long int ans1 = N;
        int count1 = 1;
        for( int i = N-1; i >= 1; i--)
        {
            if( gcd( ans1, i) == 1 )
            {
                ans1 *= i;
                count1++;
            }
            if( count1 == 4) break;
        }
        long long int ans2 = N-1;
        int count2 = 1;
        for( int i = N-2; i >= 1; i--)
        {
            if( gcd( ans2, i) == 1 )
            {
                ans2 *= i;
                count2++;
            }
            if( count2 == 4) break;
        }
        return max(ans1,ans2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends
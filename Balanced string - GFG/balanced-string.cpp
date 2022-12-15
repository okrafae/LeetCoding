//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        // code here
        string ans = "";
        string com = "abcdefghijklmnopqrstuvwxyz";
        for( int i = 0; i < N/26; i++) ans += com;
        int n = N%26;
        if( N%2 == 0 )
        {
            for( int i = 0; i < n; i++)
            {
                if( i < n/2 )
                {
                    ans += char(97+i);
                }
                else
                {
                    ans += char(123 - n + i);
                }
            }
        }
        else
        {
            int sum = 0;
            while( N > 0)
            {
                int rem = N%10;
                sum += rem;
                N /= 10;
            }
            if( sum%2 == 0 )
            {
                for( int i = 0; i < n; i++)
                {
                    if( i <= n/2 )
                    {
                        ans += char(97+i);
                    }
                    else
                    {
                        ans += char(123 - n + i);
                    }
                }
            }
            else
            {
                for( int i = 0; i < n; i++)
                {
                    if( i < n/2 )
                    {
                        ans += char(97+i);
                    }
                    else
                    {
                        ans += char(123 - n + i);
                    }
                }
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
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
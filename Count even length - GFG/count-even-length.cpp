//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
	
	int compute_value(int n)
	{
	    // Code here
	    long long int ncr = 1;
	    long long int mod = 1e9+7;
	    long long int ans = 1;
	    for( int r = 1; r <= n; r++)
	    {
	        ncr = ((ncr)%mod * ( n -r +1)%mod)%mod;
	        ncr = (ncr*(modInverse(r,mod))%mod)%mod;
	        ncr %= mod;
	        ans += ((ncr*ncr)%mod)%mod;
	        ans %= mod;
	    }
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
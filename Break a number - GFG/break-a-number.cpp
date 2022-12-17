//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int waysToBreakNumber(int N){
        // code here 
        long long int n1 = (N+1)%1000000007;
        long long int n2 = (N+2)%1000000007;
        if( n1%2 == 0 ) n1 /= 2;
        else n2 /= 2;
        return (n1*n2)%1000000007;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
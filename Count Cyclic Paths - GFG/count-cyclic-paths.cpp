//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
     int countPaths(int N){
        // code here 
        if( N == 1 ) return 0;
        if( N == 2 ) return 3;
        long long int num1 = 3, num2 = 6;
        for( int i = 3; i < N; i++)
        {
            long long int temp1 = num1, temp2 = num2;
            
            num1 = num2;
            num2 = ((temp1*3)%1000000007 + (temp2*2)%1000000007)%1000000007;
        }
        return num2;
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
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
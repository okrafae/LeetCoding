//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int count = 0, n = S.size();
        
        for( int i = 0;i < n; i++)
        {
            int uCount = 0, lCount = 0;
            for( int j = i; j < n; j++)
            {
                if( S[j] >= 'A' && S[j] <= 'Z' ) uCount++;
                else lCount++;
                
                if( uCount == lCount ) count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends
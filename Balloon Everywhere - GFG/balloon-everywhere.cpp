//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int n = s.size();
        unordered_map<char,int> m;
        for( int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        return min({ m['b'], m['a'], m['l']/2, m['o']/2, m['n']});
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
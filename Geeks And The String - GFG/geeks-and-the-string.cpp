//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        int n = s.size();
        stack<char> stk;
        for( int i = 0; i < n; i++)
        {
            if( stk.empty() ) stk.push(s[i]);
            else if( stk.top() == s[i]  ) stk.pop();
            else stk.push(s[i]);
        }
        if( stk.empty() ) return "-1";
        string ans = "";
        while( !stk.empty() )
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
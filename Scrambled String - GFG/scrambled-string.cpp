//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    bool solve( string s1, string s2, unordered_map<string,bool> &m)
    {
        if( s1.size() == 1 ) return s1 == s2;
        if( s1 == s2 ) return true;
        
        string key = s1+'*'+s2;
        
        if( m.find(key) != m.end() ) return m[key];
        int n = s1.size();
        vector<int> freq(26,0);
        for( int i = 0; i < n; i++)
        {
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if( freq[i] != 0 ) return m[key] = false;
        }
        
        for( int i = 1; i < n; i++)
        {
            if( ( ( ( solve( s1.substr(0,i), s2.substr(0,i), m )  ) && ( solve( s1.substr(i), s2.substr(i), m ) ) ) 
            || ( ( solve( s1.substr(0,i), s2.substr(n-i), m ) ) && ( solve( s1.substr(i), s2.substr(0,n-i), m ) ) ) ) )
            {
                return m[key] = true;
            }
        }
        return m[key] = false;
    }
    
    public:
    bool isScramble(string S1, string S2){
        //code here
        int n = S1.size();
        unordered_map<string,bool> m;
        return solve( S1, S2, m);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
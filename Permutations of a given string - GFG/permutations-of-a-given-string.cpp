//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    void helper(int i, int n, string &str, vector<string> &ans, vector<int> &taken, string &S)
    {
        if( i == n )
        {
            int size = ans.size();
            for( int x = 0; x < size; x++)
            {
                if( ans[x] == str ) return;
            }
            ans.push_back(str);
            return;
        }
        
        for( int j = 0; j < n; j++)
        {
            if( taken[j] != 1 )
            {
                taken[j] = 1;
                str += S[j];
                helper( i+1, n, str, ans, taken, S );
                taken[j] = 0;
                str.pop_back();
            }
        }
    }
    
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int n = S.size();
		    sort(S.begin(),S.end());
		    vector<string> ans;
		    vector<int> taken(n,0);
		    string str = "";
		    helper( 0, n, str, ans, taken, S);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
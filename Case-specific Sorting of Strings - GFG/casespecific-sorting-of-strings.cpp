//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string lc = "";
        string uc = "";
        for( int i = 0; i < n;i++)
        {
            if( str[i] >= 'a' && str[i] <= 'z') lc += str[i];
            else uc += str[i];
        }
        sort( lc.begin(),lc.end() );
        sort( uc.begin(), uc.end());
        string ans = "";
        int j = 0, k = 0;
        for( int i = 0; i < n; i++)
        {
            if( str[i] >= 'a' && str[i] <= 'z')
            {
                ans += lc[j++];
            }
            else ans += uc[k++];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
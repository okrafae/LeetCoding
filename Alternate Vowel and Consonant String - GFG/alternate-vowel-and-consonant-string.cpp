//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

    bool isVowel( char S)
    {
        if( S == 'a' || S == 'e' || S == 'i' || S == 'o' || S == 'u' ) return true;
        return false;
    }
    
class Solution{
    public:
    

    
    string rearrange (string S, int N)
    {
        // your code here
        vector<int> c(26,0),v(26,0);
        int vowelCount = 0, consCount = 0;
        for( int i = 0; i < N; i++)
        {
            if( isVowel(S[i]) )
            {
                v[S[i]- 'a']++;
                vowelCount++;
            }
            else
            {
                c[S[i] - 'a']++;
                consCount++;
            }
        }

        if( abs( vowelCount - consCount ) > 1 ) return "-1";
        
        int n = 0, fv = 0, fc = 0;
        while( fv < 26 && v[fv] == 0 ) fv++;
        while( fc < 26 && c[fc] == 0 ) fc++;
        int i = fv, j = fc;
        string ans = "";
        int flag = 0;
        if( vowelCount < consCount || fv > fc ) flag = 1;
        if( vowelCount > consCount ) flag = 0;
        while( n < N )
        {
            if( n%2 == flag )
            {
                while( i < 26 && v[i] == 0 ) i++;
                v[i]--;
                ans += char(i+'a');
            }
            else
            {
                while( j < 26 && c[j] == 0 ) j++;
                c[j]--;
                ans += char(j+'a');
            }
            n++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(),words.end());
        int n = words.size();
        unordered_map<string,int> m;
        for( int i = 0; i < n; i++)
        {
            m[words[i]]++;
        }
        string ans = "";
        for( int i = 0; i < n; i++)
        {
            int size = words[i].size(), j = 0;
            string temp = "";
            for( j = 0; j < size; j++ )
            {
                temp += words[i][j];
                if( m[temp] == 0 ) break;
            }
            if( j == size && temp.size() > ans.size() ) ans = temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends
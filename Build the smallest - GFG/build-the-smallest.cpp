//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    int n = num.size();
    if( k == n ) return "0";
    int count = 0;
    vector<bool> present(n,true);
    for( int i = 0; i < n-1 ; i++)
    {
        if( present[i] )
        {
            if( num[i] > num[i+1] )
            {
                present[i] = false;
                count++;
                if( count == k) break;
                int j = i;
                while( j >= 0  )
                {
                    if( present[j] )
                    {
                        if( num[j] > num[i+1] )
                        {
                            present[j] = false;
                            count++;
                            if( count == k) break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    j--;
                }
                if( count == k ) break;
            }
        }
    }
    int x = n - 1;
    while( x >= 0 && count != k )
    {
        if( present[x] )
        {
            present[x] = false;
            count++;
        }
        x--;
    }
    
    x = 0;
    while( x < n )
    {
        if( !present[x] ) x++;
        else
        {
            if( num[x] == '0' )
            {
                present[x] = false;
                x++;
            }
            else
            {
                break;
            }
        }
    }
    string ans = "";
    for( int i = 0; i < n; i++)
    {
        if( present[i] ) ans += num[i];
    }
    if( ans == "") return "0";
    return ans;
}
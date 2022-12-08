//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> isPrime(1000001,1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for( int i = 2; i*i < 1000000; i++)
        {
            if( isPrime[i] )
            {
                // isPrime[i].second = ++count;
                for( long long int j = i*i; j < 1000000; j+=i)
                {
                    isPrime[j] = 0;
                }
            }
            // else
                // isPrime[i].second = count;
        }
        int count = 0;
        for( int i = 2; i < 1000000; i++)
        {
            if( isPrime[i])
            {
                count++;
                isPrime[i] = count;
            }
            else
            {
                isPrime[i] = count;
            }
        }
        vector<int> ans(q,0);
        for( int i = 0; i < q; i++)
        {
            int sroot = sqrt(query[i] );
            ans[i] = isPrime[sroot];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
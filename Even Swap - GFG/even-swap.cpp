//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int low=0,high=1;
            while(low<n && high <n){
                if((a[high-1]+a[high])%2==0){
                    high++;
                    // cout<< high<< endl;
                }else{
                    sort(a.begin()+low,a.begin()+high,greater<int>());
                    low=high;
                    high+=1;
                }
            }
            if(high-low>0){
                sort(a.begin()+low,a.begin()+high,greater<int>());

            }
            return a;
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
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
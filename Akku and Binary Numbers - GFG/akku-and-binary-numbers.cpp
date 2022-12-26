//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    
    long long int binarySearchUpperBound( long long int low, long long int high, long long int target, vector<long long int> &ans)
    {
        while( low <= high )
        {
            long long int mid = low + ( high - low)/2;
            if( ans[mid] == target )
            {
                return mid;
            }
            else if( ans[mid] < target ) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    
    long long int binarySearchLowerBound( long long int low, long long int high, long long int target, vector<long long int> &ans)
    {
        while( low <= high )
        {
            long long int mid = low + ( high - low)/2;
            if( ans[mid] == target )
            {
                return mid;
            }
            else if( ans[mid] < target ) low = mid + 1;
            else high = mid - 1;
        }
        return low-1;
    }
    
    long long solve(long long l, long long r){
        // Code Here
        // vector<long long int> ans;
        long long int count = 0;
        for( int i = 0; i < 63; i++)
        {
            for( int j = i + 1; j < 63; j++)
            {
                for( int k = j + 1; k < 63; k++)
                {
                    long long int temp = pow(2,i) + pow(2,j) + pow(2,k);
                    if( temp >= l && temp <= r) count++;
                    // ans.push_back(temp);
                }
            }
        }
        return count;
        // sort( ans.begin(), ans.end());
    //     int n = ans.size();
    //     return binarySearchLowerBound( 0 , n , r, ans ) - binarySearchUpperBound( 0 , n, l, ans) + 1;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends
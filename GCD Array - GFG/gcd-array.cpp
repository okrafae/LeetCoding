//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
        for( int i = 1; i < N; i++) arr[i] += arr[i-1];
        int sum = arr[N-1];
        vector<int> factor;
        for( int i = 1; i*i <= sum; i++)
        {
            if( sum%i == 0 )
            {
                factor.push_back(i);
                factor.push_back(sum/i);
            }
        }
        sort(factor.begin(),factor.end(), greater<int>() );
        int n = factor.size();
        for( int i = 0; i < n; i++)
        {
            int partitionCount = 0;
            for( int j = 0; j < N; j++)
            {
                if( arr[j] % factor[i] == 0)
                {
                    partitionCount++;
                    if( partitionCount >= K ) return factor[i];
                }
            }
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
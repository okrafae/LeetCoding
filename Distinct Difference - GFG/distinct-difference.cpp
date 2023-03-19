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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int> ans(N,0);
        vector<int> left(N,0);
        vector<int> right(N,0);
        unordered_map<int,int> ml;
        for( int i = 0; i < N - 1; i++)
        {
            ml[A[i]]++;
            left[i+1] = ml.size();
        }
        unordered_map<int,int> mr;
        for( int i = N - 1; i > 0; i--)
        {
            mr[A[i]]++;
            right[i-1] = mr.size();
        }
        for( int i = 0; i < N; i++)
        {
            ans[i] = left[i] - right[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends
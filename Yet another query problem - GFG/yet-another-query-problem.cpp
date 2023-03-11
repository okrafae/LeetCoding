//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> solveQueries(int n, int num, vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        unordered_map<int,int> freq;
        vector<int> count(n,0);
        for(int i = n-1;i>=0;i--)
        {
            freq[arr[i]]++;
            count[i] = freq[arr[i]];
        }
        vector<int> res;
        for(int i = 0;i<num;i++){
           int l = queries[i][0],r = queries[i][1] ,k = queries[i][2];
           int counter = 0;
           for(int j = l;j<=r;j++){
               if(count[j] == k){
                counter++;
               }
           }
           res.push_back(counter);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
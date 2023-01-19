//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int ac = A, ad = A, bc = B, bd = B;
        int case1 = 0, case2 = 0;
        while( ac > C )
        {
            ac/=2;
            case1++;
        }
        while( ad > D)
        {
            ad/=2;
            case2++;
        }
        while( bc > C)
        {
            bc/=2;
            case2++;
        }
        while( bd > D)
        {
            bd/=2;
            case1++;
        }
        return min( case1, case2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
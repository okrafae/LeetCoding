//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int set_bits_in_b = 0;
        while(b)
        {
            set_bits_in_b += b & 1;
            b >>= 1;
        }
        int ans=0;
        for(int i=30;i>=0;i--){
            if(a&(1<<i) and set_bits_in_b>0){
                ans|=1<<i;
                set_bits_in_b--;
            }
        }
        int i=0;
        while(set_bits_in_b>0){
            while(a&(1<<i)) i++;
            ans|=1<<i;
            set_bits_in_b--;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
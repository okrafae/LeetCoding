//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int> arr(k,0);
        int n = nums.size();
        if( n%2 != 0 ) return false;
        for( int i = 0; i < n; i++)
        {
            arr[(nums[i]%k)]++;
        }
        if( arr[0]%2 != 0) return false;
        for( int i = 1; i<=k/2 ; i++)
        {
            if( arr[i] != arr[k-i] ) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
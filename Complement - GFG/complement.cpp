//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here

        vector<int> ans;
        int minSum = 1, sum = 0;
        int left = 1, right = 1, nextLeft = 0;
        for( int i = 0; i < n; i++)
        {
            int curr = (str[i] == '1' ) ? 1 : -1;
            sum += curr;
            if( minSum > sum )
            {
                right = i + 1;
                left = nextLeft + 1;
                minSum = sum;
            }
            if( sum > 0 )
            {
                nextLeft = i + 1;
                sum = 0;
            }
        }
        if( minSum >= 0)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(left);
            ans.push_back(right);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        if( n == 1) return 0;
        int case_1_max = INT_MIN, case_2_max = INT_MIN, case_1_min = INT_MAX, case_2_min = INT_MAX;
        for( int i = 0; i < n; i++)
        {
            case_1_max = max( case_1_max, arr[i] - i);
            case_1_min = min( case_1_min, arr[i] - i);
            case_2_max = max( case_2_max, arr[i] + i);
            case_2_min = min( case_2_min, arr[i] + i);
        }
        return max( case_1_max - case_1_min, case_2_max - case_2_min);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends
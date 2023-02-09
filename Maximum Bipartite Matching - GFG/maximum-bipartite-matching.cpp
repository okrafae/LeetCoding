//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool helper( int i, int &n, int &m, vector<int> &jobAssigned, vector<int> &visited, vector<vector<int>> &G)
    {
        for( int a = 0; a < n; a++)
        {
            if( G[i][a] and !visited[a] )
            {
                visited[a] = 1;
                if( jobAssigned[a] == -1)
                {
                    jobAssigned[a] = i;
                    return true;
                }
                else if( helper( jobAssigned[a], n, m, jobAssigned, visited, G))
                {
                    jobAssigned[a] = i;
                    return true;
                }
            }
        }
        return false;
    }

	int maximumMatch(vector<vector<int>>&G){
	    // Code here
	    int n = G[0].size();
	    int m = G.size();
	    vector<int> jobAssigned(n,-1);
	    int ans = 0;
	    for( int i = 0; i < m; i++)
	    {
	        vector<int> visited(n,0);
	        if( helper(i,n,m,jobAssigned,visited,G)) ans++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends
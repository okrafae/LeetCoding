//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
	    vector<vector<int>> ans(n,vector<int> (m,-1));
	    queue<pair<int,int>> q;
	    int distance = 0;
	    for( int i = 0; i< n; i++)
	    {
	        for( int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == 1) 
	            {
	                pair<int,int> temp(i,j);
	                ans[i][j] = distance;
	                q.push(temp);
	            }
	        }
	    }
	    
	    while( !q.empty() )
	    {
	        int s = q.size();
	        distance++;
	        while( s-- )
	        {
	            pair<int,int> temp = q.front();
	            q.pop();
	            for( int i = 0; i < 4; i++)
	            {
	                int nx = temp.first + dir[i][0];
	                int ny = temp.second + dir[i][1];
	                if( nx >= 0 && ny >= 0 && nx < n && ny < m && ans[nx][ny] == -1 )
	                {
	                    pair<int,int> t(nx,ny);
	                    q.push(t);
	                    ans[nx][ny] = distance;
	                }
	            }
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
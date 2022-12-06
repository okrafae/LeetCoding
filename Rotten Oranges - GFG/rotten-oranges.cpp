//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir{ {0,1},{1,0},{0,-1},{-1,0}};
        int time = 0;
        queue<vector<int>> q;
        for( int i = 0; i < n; i++)
        {
            for( int j = 0; j < m; j++)
            {
                if( grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        while( !q.empty())
        {
            int s = q.size();
            time++;
            while( s-- )
            {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                for( int i = 0;i < 4; i++)
                {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if( nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1)
                    {
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
        }
        for( int i = 0; i < n; i++)
        {
            for( int j = 0; j < m; j++)
            {
                if( grid[i][j] == 1 ) return -1;
            }
        }
        return time-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
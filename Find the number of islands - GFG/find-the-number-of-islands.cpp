//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void bfs(int i,int j,int n,int m, vector<vector<int>> &vis, vector<vector<char>> &grid)
    { 
        queue<vector<int>> q;
        q.push({i,j});
        while( !q.empty() )
        {
            int s = q.size();
            while( s-- )
            {
                vector<int> temp = q.front();
                q.pop();
                for( int x = -1; x <= 1; x++)
                {
                    for( int y = -1; y <= 1; y++)
                    {
                        int nx = temp[0] +x;
                        int ny = temp[1] +y;
                        if( nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' && !vis[nx][ny] )
                        {
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int islandsCount = 0;
        for( int i = 0; i < n; i++)
        {
            for( int j = 0; j < m; j++)
            {
                if( grid[i][j] == '1' && !vis[i][j] )
                {
                    islandsCount++;
                    vis[i][j] = 1;
                    bfs(i,j,n,m,vis,grid);
                }
            }
        }
        return islandsCount;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
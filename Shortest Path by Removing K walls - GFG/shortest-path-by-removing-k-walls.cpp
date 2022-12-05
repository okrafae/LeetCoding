//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> vis(n, vector<int> (m,-1));
        
        queue<vector<int>> q;
        if( mat[0][0] == 1 )
        {
            q.push({0,0,k-1});
            vis[0][0] = k-1;
        }
        else
        {
            q.push({0,0,k});
            vis[0][0] = k;
        }

        int shortestPath = 0;
        while( !q.empty() )
        {
            int s = q.size();
            shortestPath++;
            while(s--)
            {
                vector<int> temp = q.front();
                q.pop();
                
                if( temp[0] == n-1 && temp[1] == m-1 )
                {
                    return shortestPath-1;
                }
   
                for( int i = 0; i < 4; i++)
                {
                    int nx = temp[0] + dir[i][0];
                    int ny = temp[1] + dir[i][1];
                    int nk = temp[2];
                    
                    if( nx >= 0 && ny >= 0 && nx < n && ny < m )
                    {
                        if( vis[nx][ny] < nk )
                        {
                            if( mat[nx][ny] == 1 && nk > 0 )
                            {
                                vis[nx][ny] = nk-1;
                                q.push({nx,ny,nk-1});
                            }
                            else if( mat[nx][ny] == 0 )
                            {
                                vis[nx][ny] = nk;
                                q.push({nx,ny,nk});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
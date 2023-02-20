//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool is_valid(int x, int y,int N,int M)
    {
        if (x < 0 || x >= N || y < 0 || y >= M) return false;
    
        return true;
    }
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};


    int minIteration(int n, int m, int x, int y){    

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({0,{x-1,y-1}});
        vis[x-1][y-1] = 1;
        
        int ans = 0;
        while(!q.empty())
        {
            int lvl = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(is_valid(nx,ny,n,m) && vis[nx][ny] == 0)
                {
                    vis[nx][ny] = 1;
                    q.push({lvl+1,{nx,ny}});
                    
                    ans = max(ans, lvl+1);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
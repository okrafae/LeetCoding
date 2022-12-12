//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void dfs(int node, int parent, int tin[], int low[], vector<int> &vis, vector<int> &mark, int &call, vector<int> adj[])
  {
      vis[node] = 1;
      tin[node] = call;
      low[node] = call;
      call++;
      int child = 0;
      for( auto it : adj[node] )
      {
          if( !vis[it] )
          {
              dfs(it, node, tin, low, vis, mark, call, adj );
              low[node] = min( low[node], low[it]);
              if( low[it] >= tin[node] && parent != -1)
              {
                  mark[node] = 1;
              }
              child++;
          }
          else
          {
              low[node] = min( low[node], tin[it]);
          }
      }
      if( parent == -1 && child > 1) mark[node] = 1;
  }
  

    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V,0), mark(V,0);
        int call = 0;
        int tin[V];
        int low[V];
        for( int i = 0; i < V ; i++)
        {
            if( !vis[i] )
            dfs( i , -1, tin, low, vis, mark, call, adj);
        }
        vector<int> ans;
        for( int i = 0; i < V; i++)
        {
            if( mark[i] == 1 ) ans.push_back(i);
        }
        if( ans.size() == 0 )
        {
            ans.push_back(-1);
            return ans;
        }
        return ans;
        // Code here
    }
};
        


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
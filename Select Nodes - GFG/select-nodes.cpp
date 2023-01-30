//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    int ans;

public:
    bool isLeaf(int node, int par, vector<int> adj[])
    {
        int cnt = 0;
        for (auto i : adj[node])
            if (i != par)
                cnt++;
        return cnt == 0;
    }
    bool dfs(int node, int par, vector<int> adj[])
    {
        if (isLeaf(node, par, adj))
            return true;

        bool flag = false;
        for (auto i : adj[node])
            if (i != par)
                flag |= dfs(i, node, adj);

        if (flag)
            ans++;

        return !flag;
    }
    int countVertex(int N, vector<vector<int>> edges)
    {
        ans = 0;
        vector<int> adj[N + 1];
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(N + 1);
        dfs(1, -1, adj);
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
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
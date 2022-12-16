//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        int answer = 0;
        if( ty == 0)
        {
            if( j % 2 == 0 )
            {
                int dir_avantika[6][2] = { {-1,-1}, {0,-1},{1,0},{0,1},{-1,1},{-1,0} };
                for( int k = 0; k < 6; k++)
                {
                    int nx = i + dir_avantika[k][0];
                    int ny = j + dir_avantika[k][1];
                    if( nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        answer += mat[nx][ny];
                    }
                }
            }
            else
            {
                int dir_avantika[6][2] = { {0,-1}, {1,-1},{1,0},{1,1},{0,1},{-1,0} };
                for( int k = 0; k < 6; k++)
                {
                    int nx = i + dir_avantika[k][0];
                    int ny = j + dir_avantika[k][1];
                    if( nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        answer += mat[nx][ny];
                    }
                }
            }
        }
        else
        {
            int dir_aakriti_even[12][2] = { {-1,-2},{0,-2},{1,-2},{1,-1},{2,0},{1,1},{1,2},{0,2},{-1,2},{-2,1},{-2,0},{-2,-1} };
            int dir_aakriti_odd[12][2] = { {-1,-1},{-1,-2},{0,-2},{1,-2},{2,-1},{2,0},{2,1},{1,2},{0,2},{-1,2},{-1,1},{-2,0} };
            if( j % 2 == 0 )
            {
                for( int k = 0; k < 12; k++)
                {
                    int nx = i + dir_aakriti_even[k][0];
                    int ny = j + dir_aakriti_even[k][1];
                    if( nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        answer += mat[nx][ny];
                    }
                }
            }
            else
            {
                for( int k = 0; k < 12; k++)
                {
                    int nx = i + dir_aakriti_odd[k][0];
                    int ny = j + dir_aakriti_odd[k][1];
                    if( nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        answer += mat[nx][ny];
                    }
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
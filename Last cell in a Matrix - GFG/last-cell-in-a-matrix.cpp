//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i = 0, j = 0, dir = 0;
        while( i >= 0 && i < R && j >= 0 && j < C)
        {
            if( matrix[i][j] == 1 )
            {
                matrix[i][j] = 0;
                dir = (dir+1)%4;
            }
            if( dir == 0 ) j++;
            else if( dir == 1 ) i++;
            else if( dir == 2 ) j--;
            else i--;
        }
        
        if( dir == 0 ) return {i,j-1};
        else if( dir == 1 ) return {i-1,j};
        else if( dir == 2 ) return {i,j+1};
        else return {i+1,j};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
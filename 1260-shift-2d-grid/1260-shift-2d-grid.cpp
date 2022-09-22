class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k%(m*n);
        vector<vector<int>> newgrid;
        for( int i = 0; i < m; i++)
        {
            vector<int> temp;
            for( int j = 0; j < n; j++)
            {
                temp.push_back( grid[i][j]);
            }
            newgrid.push_back(temp);
        }
        for( int i = 0; i < m; i++)
        {
            for( int j = 0; j < n; j++)
            {
                grid[(i+(j+k)/n)%m][(j+k)%n] = newgrid[i][j];
            }
        }
        return grid;
    }
};
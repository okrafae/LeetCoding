class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row_flag(m,1);
        vector<int> col_flag(n,1);
        for( int i = 0; i < m; i++)
        {
            for( int j = 0; j < n; j++)
            {
                if( matrix[i][j] == 0 )
                {
                    row_flag[i] = 0;
                    col_flag[j] = 0;
                }
            }
        }
        
        for( int i = 0; i < m; i++)
        {
            if( row_flag[i] == 0 )
            {
                for( int j = 0; j < n; j++) matrix[i][j] = 0;
            }
        }
        
        for( int j = 0; j < n; j++)
        {
            if( col_flag[j] == 0 )
            {
                for( int i = 0; i < m; i++) matrix[i][j] = 0;
            }
        }
    }
};
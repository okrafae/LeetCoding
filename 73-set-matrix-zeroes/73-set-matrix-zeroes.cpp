class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int colflag = 1;
        
        //taking a flag if 0th column contains a zero
        
        for( int i = 0; i < m; i++)
        {
            if( matrix[i][0] == 0 ) colflag = 0;
            for( int j = 1; j < n; j++)
            {
                if( matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //iterating in reverse manner to avoid changes in first row effect others
        
        for( int i = m - 1; i >= 0; i--)
        {
            for( int j = n - 1; j >= 1; j--)
            {
                if( matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if( colflag == 0 )
            {
                matrix[i][0] = 0;
            }
        }
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int colLow = 0, colHigh = m - 1,colMid =0;
        while( colLow <= colHigh )
        {
            colMid = (colLow + colHigh ) /2;
            if( target == matrix[colMid][0] ) return true;
            else if( target < matrix[colMid][0] ) colHigh = colMid - 1;
            else
                colLow = colMid+1;
        }
        int rowLow = 0, rowHigh = n -1,rowMid =0;
        cout << colLow << " " << colMid << " " << colHigh << endl;
        if( colHigh < 0) colHigh++;
         //return false;
        while( rowLow <= rowHigh )
        {
            rowMid = ( rowLow + rowHigh ) / 2;
            if( target == matrix[colHigh][rowMid]) return true;
            else if( target < matrix[colHigh][rowMid]) rowHigh = rowMid - 1;
            else rowLow = rowMid + 1;
        }
        cout << rowLow << " " << rowMid << " " << rowHigh << endl;

        return false;
    }
};
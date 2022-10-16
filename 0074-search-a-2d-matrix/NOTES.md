class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
int m = matrix.size(), n = matrix[0].size();
int colLow = 0, colHigh = m - 1,colMid =0;
//binary searching first column
while( colLow <= colHigh )
{
colMid = (colLow + colHigh ) /2;
if( target == matrix[colMid][0] ) return true;
else if( target < matrix[colMid][0] ) colHigh = colMid - 1;
else
colLow = colMid+1;
}
int rowLow = 0, rowHigh = n -1,rowMid =0;
//to avoid edge case like [[1]] & target = 0. to search in first row.
if( colHigh < 0) colHigh++;
//binary searching the row in which it might be present
while( rowLow <= rowHigh )
{
rowMid = ( rowLow + rowHigh ) / 2;
if( target == matrix[colHigh][rowMid]) return true;
else if( target < matrix[colHigh][rowMid]) rowHigh = rowMid - 1;
else rowLow = rowMid + 1;
}
​
return false;
}
};
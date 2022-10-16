class Solution {
public:
    int uniquePaths(int m, int n) {
        int maxVal = max(m-1,n-1);
        int minVal = min(m-1,n-1);
        //(m+n)!/(m!)*(n!)
        long long int noOfWays = 1;
        for( int i = maxVal + minVal, j = 1; i > maxVal; i--,j++)
        {
            noOfWays *= i;
            noOfWays /= j;
        }
        return (int)noOfWays;
    }
};
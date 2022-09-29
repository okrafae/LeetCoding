class Solution {
public:
    double helper(double a,int n)
    {
        if( a == 0 ) return 0;
        if( n == 1 ) return a;
        if( n == 0 ) return 1;
        double temp = helper(a,n/2);
        if( n%2 == 0 )
        {
            return temp * temp;
        }
        else
        {
            return temp * temp * a;
        }
    }
    double myPow(double x, int n) {
        
        double ans = helper(abs(x),abs(n));
        if( n < 0)
        {
            if( x > 0 || n % 2 == 0)
                return 1/ans;
            else
                return -1/ans;
        }
        else
        {
            if( x > 0 || n%2 == 0)
                return ans;
            else
                return -1*ans;
        }
    }
};
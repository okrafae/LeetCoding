class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0) return 1;
        double ans = myPow(x,abs(n/2));
        if( n%2 == 0 )
        {
            if( n < 0 ) return 1/(ans*ans);
            return ans*ans;
        }
        else
        {
            if( n < 0) return 1/(ans*ans*x);
            return ans*ans*x;
        }
    }
};
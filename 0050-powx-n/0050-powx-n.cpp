class Solution {
public:

    double solve( double x, long long n)
    {
        if( n==0) return 1;

        if( n<0) return solve( (1/x), -n);

        if( n%2 == 0)
        return solve ( x*x, n/2);

        else if( n%2 == 1)
        return  x* solve( x*x, (n-1)/2);

    return 0;
    }
    double myPow(double x, int n) {
        
        return solve ( x, (long long)n);
    }
};
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        
        long A = a ;
        long B = b;

        long mod = (long)(pow(10,9)+7);
        //get LCM

        //first get GCD
        while( B >0)
        {
            long temp = A;
             A=B ; 
             B = temp % B;
        }

        long lcm = ( (long)a*b)/A;

        long low = min(a,b);

        long high = (long)n * min(a,b);
        while( low<high) //loop will break when l == h
        {
            long m = low + (high - low)/2;

            if ( m/a + m/b - (m/lcm) < n )
            low = m+1;

            else if(m/a + m/b - (m/lcm) >=n)
            high = m;
        }

        return (int)(low % mod);
    }
};
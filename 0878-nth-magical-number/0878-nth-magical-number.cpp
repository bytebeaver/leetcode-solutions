class Solution {
public:

    int nthMagicalNumber(int n, int a, int b) {

        long A = a;
        long B = b;

        long mod = (long)(pow(10, 9) + 7);


        // Find GCD using Euclidean Algorithm
        while (B > 0)
        {
            long temp = A;
            A = B;
            B = temp % B;
        }

        // A now contains GCD(a, b)

        // LCM = (a * b) / GCD
        long lcm = ((long)a * b) / A;


        // Smallest possible magical number
        long low = min(a, b);

        // nth multiple of min(a,b) is always magical
        // so this is an upper bound
        long high = (long)n * min(a, b);


        // Binary search for the nth magical number
        while (low < high)
        {
            long m = low + (high - low) / 2;

            // Count magical numbers <= m
            // Subtract multiples of LCM to avoid
            // counting numbers divisible by both twice.
            long count = m / a + m / b - m / lcm;

            if (count < n)
            {
                // Not enough magical numbers
                // Answer must be larger.
                low = m + 1;
            }
            else
            {
                // At least n magical numbers exist.
                // m could be the answer, so search left.
                high = m;
            }
        }

        // low == high == nth magical number
        return (int)(low % mod);
    }
};
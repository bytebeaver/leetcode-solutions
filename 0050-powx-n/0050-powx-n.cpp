class Solution {
public:

    double solve(double x, long long n)
    {
        // Base case: kisi bhi number ka power 0 hamesha 1 hota hai
        if (n == 0) return 1;

        // Agar n negative hai, to x^n = (1/x)^(-n)
        // Isliye base ko invert karke, power ko positive bana denge
        if (n < 0) return solve((1 / x), -n);

        // Agar n even hai: x^n = (x*x)^(n/2)
        // Yeh recursion ko O(log n) tak le aata hai (naive O(n) ki jagah)
        if (n % 2 == 0)
            return solve(x * x, n / 2);

        // Agar n odd hai: x^n = x * (x*x)^((n-1)/2)
        // Ek extra 'x' nikal ke baaki even power mein todte hain
        else if (n % 2 == 1)
            return x * solve(x * x, (n - 1) / 2);

        return 0; // Yeh line kabhi execute nahi hogi (safety fallback for compiler)
    }

    double myPow(double x, int n) {
        // n ko long long mein cast kar rahe hain kyunki agar n = INT_MIN ho,
        // to -n karne par int overflow ho jaata (INT_MIN ka positive int range mein nahi aata)
        return solve(x, (long long)n);
    }
};
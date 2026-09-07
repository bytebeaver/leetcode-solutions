class Solution {
public:

    int reverse(int x) {

        // Store x in long long.
        // This is important because INT_MIN = -2147483648.
        // Its positive counterpart +2147483648 cannot fit in int.
        long long num = x;

        // Keep track of whether the original number was negative.
        bool neg = false;

        // If the number is negative, remember the sign
        // and convert num to its positive magnitude.
        if (num < 0)
        {
            neg = true;
            num = -num;
        }

        // We use long long because the reversed number
        // may temporarily be larger than INT_MAX.
        long long reverse = 0;

        // Extract digits one by one from right to left.
        while (num != 0)
        {
            // Get the last digit.
            int digit = num % 10;

            // Remove the last digit from num.
            num = num / 10;

            // Add the digit to the reversed number.
            reverse = reverse * 10 + digit;
        }

        // If the original number was negative,
        // make the reversed number negative as well.
        if (neg)
        {
            reverse = -reverse;
        }

        // The answer must fit in a 32-bit signed integer.
        // If it doesn't, the problem asks us to return 0.
        if (reverse > INT_MAX || reverse < INT_MIN)
        {
            return 0;
        }

        // The value is within the int range,
        // so it is safe to convert it back to int.
        return (int)reverse;
    }
};
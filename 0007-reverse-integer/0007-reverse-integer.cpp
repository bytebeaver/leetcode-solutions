class Solution {
public:
    int reverse(int x) {
        
        bool neg = false;
        
        long long num = x;
        

        if( num<0)
        {
            neg = true;
            num = -num;
        }

        long long  reverse = 0;

        while( num !=0 )
        {
            int digit = num%10;

            num = num/10;

            reverse = reverse*10 + digit;
        }


        if( neg )
        {
            reverse = - reverse;
        }

        if( reverse > INT_MAX || reverse < INT_MIN)
        return 0;

    return (int)reverse;

    }
};
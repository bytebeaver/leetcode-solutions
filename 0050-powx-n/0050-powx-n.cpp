class Solution {
public:
    double myPow(double x, int n) {
        
       if(n==0)
       {
           return 1;
       }

    double fn1=myPow(x,n/2);

     double fn= fn1*fn1;

      if(n%2==1)
      {
          fn=x*fn;
      }
      else if (n % 2 == -1) {
        fn /= x;
    }

      return fn;
      
    }
};
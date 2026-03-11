class Solution {
public:
    int bitwiseComplement(int n) {
        

        if (n==0)
        return 1;
        
        int i;
        int j;
        int k;
        stack <int>comp;
        int result=0;

        while(n>0)
        {
            i=n%2;
            i==0?comp.push(1):comp.push(0);
            n=n/2;
        }

        while(!comp.empty())
        {
            j=comp.size()-1;
            k=comp.top();
            comp.pop();
            result+=k * (pow(2,j));
        }

        return result;
    }
};
//same question as the fibonacci series question on leetcode there i have written 3 approaches ..here i am doing only the most optimal one that is space optimized dp solution


class Solution {
public:
    int climbStairs(int n) {
        
        int previous_step=2;
        int previous_to_previous_step=1;

        if(n==1)return 1;

        for(int i=3; i<=n;i++)
        {
            int current_step = previous_step + previous_to_previous_step;
            previous_to_previous_step = previous_step;
            previous_step=current_step;
            

        }
        
        return previous_step;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0], nums[1]);

        vector<int>dp(n,0);
        
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);

       
         int i=n-3;

         while(i>=0)
         {
            int take = dp[i+2] + nums[i];
            
            int not_take= 0+ dp[i+1];

            dp[i] =  max(take, not_take);

            i--;

         }

         return max(dp[0], dp[1]);
    
    }
};
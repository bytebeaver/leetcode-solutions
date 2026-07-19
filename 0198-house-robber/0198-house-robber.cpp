// class Solution {
// public:
//     int rob(vector<int>& nums) {
        
//         int n = nums.size();

//         if(n==1)
//         return nums[0];

//         if(n==2)
//         return max(nums[0], nums[1]);

//         vector<int>dp(n,0);
        
//         dp[n-1] = nums[n-1];
//         dp[n-2] = max(nums[n-1], nums[n-2]);

       
//          int i=n-3;

//          while(i>=0)
//          {
//             int take = dp[i+2] + nums[i];
            
//             int not_take= 0+ dp[i+1];

//             dp[i] =  max(take, not_take);

//             i--;

//          }

//          return max(dp[0], dp[1]);
    
//     }
// };



class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0], nums[1]);

        int v1 = nums[0];
        int v2= nums[1];

        for(int i=2; i<n; i++)
        {
            int take = nums[i] + v1;
            int not_take = 0 + v2;
            v1 = max(v1,not_take);
            v2= max(v2,take);
        }

        return max(v1,v2);
    
    }
};
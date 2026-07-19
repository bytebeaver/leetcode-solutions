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

        vector<int>dp(n,0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

       
         int i=2;

         while(i<n)
         {
            int take = dp[i-2] + nums[i];
            
            int not_take= 0+ dp[i-1];

            dp[i] =  max(take, not_take);

            i++;

         }

         return dp[n-1];
    
    
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {

//         int n = nums.size();

//         if(n==1)
//         return nums[0];

//         if(n==2)
//         return max(nums[0], nums[1]);

//         int prev  = nums[0];   // best answer using only index 0
//         int prev2 = 0;         // best answer using NO elements (phantom base, like index -1)

//         for(int i=1; i<n; i++)
//         {
//             int take = nums[i] + prev2;    // include nums[i] -> add to two-back answer
//             int not_take = 0 + prev;        // exclude nums[i] -> carry forward one-back answer

//             int current_i = max(take, not_take);   // best answer up to index i

//             prev2 = prev;         // old "one-back" becomes new "two-back"
//             prev = current_i;     // new answer becomes new "one-back"
//         }

//         return prev;   // after the loop, prev holds the answer for the LAST index
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];               // sirf ek hi house
        if(n == 2) return max(nums[0], nums[1]);  // dono adjacent, max lo

        vector<int> dp(n, 0);
        vector<int> dp2(n, 0);

//index zero to index n-2 i.e first to second last element
        dp[0] = nums[0];                  // base case 1
        dp[1] = max(nums[0], nums[1]);    // base case 2

        int i = 2;
        while(i <= n-2) {
            int take = dp[i-2] + nums[i]; // is house rob karo
            int not_take = dp[i-1];       // is house skip karo

            dp[i] = max(take, not_take);  // best choice store karo

            i++;
        }

    //index 1 to index n-2 i.e seond element to last elemnet   
        dp2[1] = nums[1];                  // base case 1
        dp2[2] = max(nums[2], nums[1]);    // base case 2

        int j = 3;
        while(j <= n-1) {
            int take = dp2[j-2] + nums[j]; // is house rob karo
            int not_take = dp2[j-1];       // is house skip karo

            dp2[j] = max(take, not_take);  // best choice store karo

            j++;
        }


        return max(dp[n-2], dp2[n-1]); 
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();

        int best_ending_so_far = nums[0];
        int result = nums[0];

        for(int i=1; i<n; i++)
        {
            //we have two choices to get the best ending at current_i 

            int v1 = best_ending_so_far + nums[i];
            int v2 =  nums[i];

            best_ending_so_far = max(v1, v2);

            result = max(result, best_ending_so_far);

        }

        return result;

    }
};
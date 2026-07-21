class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();

        int best_ending_so_far = nums[0];
        int result = nums[0];

        for(int i=1; i<n; i++)
        {
            //we have two choices to get the best ending at current_i 
            int best_till_prev_index = best_ending_so_far;

            best_ending_so_far = max(nums[i], nums[i] + best_till_prev_index);

            result = max(result, best_ending_so_far);

        }

        return result;

    }
};
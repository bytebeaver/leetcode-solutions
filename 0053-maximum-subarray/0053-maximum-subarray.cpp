class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int best_ending_so_far = nums[0]; // best subarray sum ending at current index
        int result = nums[0];             // overall best subarray sum so far

        for(int i = 1; i < n; i++) {
            int v1 = best_ending_so_far + nums[i]; // extend previous subarray
            int v2 = nums[i];                      // start fresh from here

            best_ending_so_far = max(v1, v2);      // best choice at index i

            result = max(result, best_ending_so_far); // update overall best
        }

        return result;
    }
};
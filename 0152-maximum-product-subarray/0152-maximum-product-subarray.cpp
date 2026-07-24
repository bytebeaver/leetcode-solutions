class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_ending = nums[0];   // max product ending at current index
        int min_ending = nums[0];   // min product ending at current index (for negative flip)
        int result = nums[0];       // overall best answer so far

        int n = nums.size();

        for(int i=1; i<n ; i++)
        {
            int v1 = nums[i];                 // fresh start from this element
            int v2 = max_ending*nums[i];       // extend previous max
            int v3 = min_ending*nums[i];       // extend previous min (may flip to max if nums[i] < 0)

            max_ending = max(v1, max(v2, v3)); // pick best of all 3 as new max
            min_ending = min(v1, min(v2, v3)); // pick worst of all 3 as new min

            result = max(result, max_ending);  // update global answer

        }

        return result;
    }
};
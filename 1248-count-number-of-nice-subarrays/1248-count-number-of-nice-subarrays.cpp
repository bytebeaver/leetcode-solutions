//PREREQUISITE : Second approach of leetcode 930  

class Solution {
public:

    int numSubarraysWithSum_atmost_goal(vector<int>& nums, int goal) {

        // n = number of elements in the array
        int n = nums.size();

        int count = 0;

        // Sliding window pointers
        int l = 0;
        int r = 0;

        // Sum of elements in current window [l...r]
        int sum = 0;

        // If goal is negative, no subarray can have
        // sum <= goal because nums contains only 0s and 1s.
        if (goal < 0)
            return 0;

        while (r < n)
        {
            // Add current element to window
            sum += nums[r]%2;  //if nums[r] is 0 it will give 0 ..else it will give 1 

            // If sum becomes greater than goal,
            // shrink the window from the left.
            while (sum > goal)
            {
                sum -= (nums[l]%2);
                l++;
            }

            // Every subarray ending at r and starting
            // anywhere from l to r has sum <= goal.
            count += r - l + 1;

            // Move right pointer forward
            r++;
        }

        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        
         // Number of subarrays having sum <= goal
        int alpha = numSubarraysWithSum_atmost_goal(nums, k);

        // Number of subarrays having sum <= goal - 1
        int beta = numSubarraysWithSum_atmost_goal(nums, k-1);

        // Exactly goal =
        // subarrays <= goal - subarrays <= goal - 1
        return alpha - beta;
    }
};
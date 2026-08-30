class Solution {
public:

    // Returns the number of subarrays having
    // AT MOST k distinct integers
    int subarraysWith_atmost_KDistinct(vector<int>& nums, int k) {

        // No non-empty subarray can have
        // at most 0 distinct integers
        if (k == 0)
            return 0;

        int n = nums.size();

        // Sliding window pointers
        int l = 0;
        int r = 0;

        // Stores frequency of each number
        // inside the current window [l...r]
        map<int, int> num_freq;

        // Total number of valid subarrays
        int count = 0;

        while (r < n)
        {
            // Add nums[r] to the current window
            num_freq[nums[r]]++;

            // If the window contains more than k
            // distinct integers, shrink it from the left
            while (num_freq.size() > k)
            {
                // Remove nums[l] from the window
                num_freq[nums[l]]--;

                // If its frequency becomes 0,
                // it is no longer present in the window
                if (num_freq[nums[l]] == 0)
                    num_freq.erase(nums[l]);

                // Move left pointer forward
                l++;
            }

            // Current window [l...r] has at most k distinct integers.
            //
            // Every subarray ending at r and starting
            // anywhere from l to r is also valid.
            //
            // Number of such subarrays = r - l + 1
            count += r - l + 1;

            // Expand window to the right
            r++;
        }

        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // Exactly k distinct integers can be calculated as:
        //
        // Exactly k
        // = At Most k - At Most (k - 1)

        int Alpha = subarraysWith_atmost_KDistinct(nums, k);

        int Beta = subarraysWith_atmost_KDistinct(nums, k - 1);

        return Alpha - Beta;
    }
};
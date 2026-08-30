// PREREQUISITE: Second approach of LeetCode 930
//
// This problem is basically the same as LeetCode 930.
//
// In LeetCode 930, the array already contains only 0s and 1s.
// Here, nums contains arbitrary integers, but we only care
// whether each number is odd or even.
//
// So we can conceptually convert:
//
// Even number -> 0
// Odd number  -> 1
//
// We do this using nums[i] % 2.
//
// After this conversion, the problem becomes:
// "Count binary subarrays whose sum is exactly k."
//
// Therefore, we can use the same technique:
// Exactly k = AtMost(k) - AtMost(k - 1)


class Solution {
public:

    // Returns the number of subarrays containing
    // AT MOST 'goal' odd numbers.
    int numSubarraysWithSum_atmost_goal(vector<int>& nums, int goal) {

        // n = number of elements in the array
        int n = nums.size();

        // Stores the number of valid subarrays
        // having at most 'goal' odd numbers.
        int count = 0;

        // Sliding window pointers
        int l = 0;
        int r = 0;

        // Number of odd elements in the current window [l...r]
        int sum = 0;

        // If goal is negative, no subarray can contain
        // <= goal odd numbers.
        //
        // This is also required when we call this function
        // with goal = k - 1 and k = 0.
        if (goal < 0)
            return 0;

        while (r < n)
        {
            // nums[r] can be any integer.
            //
            // We only care whether nums[r] is odd or even.
            //
            // nums[r] % 2 gives:
            //
            // Even -> 0
            // Odd  -> 1
            //
            // Therefore, we treat every even number as 0
            // and every odd number as 1.
            //
            // This allows 'sum' to represent the number
            // of odd elements in the current window.
            sum += nums[r] % 2;


            // If the current window contains more than
            // 'goal' odd numbers, the window is invalid.
            //
            // Therefore, shrink the window from the left.
            while (sum > goal)
            {
                // Remove nums[l] from the current window.
                //
                // Again, we only care whether nums[l] is odd
                // or even, so we use nums[l] % 2.
                //
                // Even -> subtract 0
                // Odd  -> subtract 1
                //
                // This keeps 'sum' equal to the number of
                // odd elements currently inside [l...r].
                sum -= nums[l] % 2;

                // Move left pointer forward
                l++;
            }


            // The current window [l...r] contains
            // at most 'goal' odd numbers.
            //
            // Every subarray ending at r and starting
            // anywhere from l to r will also contain
            // at most 'goal' odd numbers.
            //
            // Number of such subarrays:
            //
            // [l...r]
            // [l+1...r]
            // [l+2...r]
            // ...
            // [r...r]
            //
            // Total = r - l + 1
            count += r - l + 1;


            // Expand the window
            r++;
        }

        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {

        // Number of subarrays having AT MOST k odd numbers
        int alpha = numSubarraysWithSum_atmost_goal(nums, k);

        // Number of subarrays having AT MOST k-1 odd numbers
        int beta = numSubarraysWithSum_atmost_goal(nums, k - 1);

        // Therefore:
        //
        // Exactly k
        // = AtMost(k) - AtMost(k-1)
        //
        // This removes all subarrays having fewer than k
        // odd numbers and leaves only subarrays having
        // exactly k odd numbers.
        return alpha - beta;
    }
};
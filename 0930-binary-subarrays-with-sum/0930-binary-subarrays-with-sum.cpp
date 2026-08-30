// Read LeetCode 560: Subarray Sum Equals K
// This problem uses the exact same Prefix Sum + Hash Map idea.
// LeetCode 560 works for general integers,
// while this problem has only 0s and 1s.

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // n = number of elements in the array
        int n = nums.size();

        // map stores:
        // prefix_sum -> number of times this prefix sum
        // has appeared so far
        //
        // Example:
        // if prefix sum 3 has occurred 4 times,
        // then mp[3] = 4
        map<int, int> mp;

        // sum = prefix sum up to the current index
        //
        // Initially, we have not processed any element,
        // so the prefix sum is 0.
        int sum = 0;

        // We consider an "empty prefix" having sum 0.
        //
        // This is important because if the subarray starting
        // from index 0 itself has sum = goal, we need to count it.
        mp[0] = 1;

        // count = total number of subarrays
        // whose sum is exactly equal to goal
        int count = 0;

        // Traverse the array
        for (int i = 0; i < n; i++)
        {
            // Add the current element to the prefix sum
            sum += nums[i];

            // We want:
            //
            // current prefix sum - previous prefix sum = goal
            //
            // Therefore:
            //
            // previous prefix sum = current sum - goal
            int prefix_sum = sum - goal;

            // Check whether we have seen this required
            // prefix sum before.
            if (mp.find(prefix_sum) != mp.end())
            {
                // Every occurrence of prefix_sum represents
                // one possible starting point of a subarray
                // ending at index i whose sum is goal.
                count += mp[prefix_sum];
            }

            // Store the current prefix sum.
            //
            // If this sum has already appeared,
            // increase its frequency.
            mp[sum]++;
        }

        // Return total number of subarrays
        // having sum exactly equal to goal.
        return count;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

        int n = nums.size();

        // Sort the array.
        // This allows us to reason about all elements
        // between l and r at once.
        sort(nums.begin(), nums.end());

        // l represents the first element of the pair.
        int l = 0;

        // r represents the second element of the pair.
        int r = n - 1;

        // Stores the total number of valid pairs.
        int ans = 0;

        while(l < r)
        {
            // Current pair.
            int sum = nums[l] + nums[r];

            // The current sum is too large or equal to target.
            //
            // (l, r) is invalid.
            //
            // Since r is the largest element in the current range,
            // we try a smaller element by moving r left.
            if(sum >= target)
            {
                r--;
            }

            // The current sum is strictly smaller than target.
            //
            // Since the array is sorted:
            //
            // nums[l] + nums[l+1]
            // nums[l] + nums[l+2]
            // ...
            // nums[l] + nums[r]
            //
            // are all <= nums[l] + nums[r].
            //
            // Since nums[l] + nums[r] < target,
            // ALL of these pairs are valid.
            //
            // Number of such pairs = r - l.
            else
            {
                ans += r - l;

                // We have counted every valid pair
                // involving nums[l], so move l forward.
                l++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        // l and r represent the left and right boundaries
        // of our current sliding window.
        int l = 0;
        int r = 0;

        // Stores the number of zeroes currently present
        // inside the window [l ... r].
        int zeroes = 0;

        // Stores the maximum length of a valid window
        // found so far.
        int max_len = 0;

        // Expand the window by moving r from left to right.
        while (r < n)
        {
            // If the newly included element is 0,
            // the number of zeroes in the window increases.
            if (nums[r] == 0)
            {
                zeroes++;
            }

            // If the window contains more than k zeroes,
            // we cannot flip all of them.
            // Therefore, shrink the window from the left
            // until it becomes valid again.
            while (zeroes > k)
            {
                // If the element being removed is a zero,
                // decrease the zero count because it is
                // no longer inside the window.
                if (nums[l] == 0)
                {
                    zeroes--;
                }

                // Move the left boundary one position right.
                l++;
            }

            // At this point zeroes <= k, so the current
            // window can be converted entirely into 1s
            // using at most k flips.
            int length = r - l + 1;

            // Keep the longest valid window encountered.
            max_len = max(max_len, length);

            // Move r right to include the next element.
            r++;
        }

        // Return the maximum number of consecutive 1s
        // obtainable after at most k flips.
        return max_len;
    }
};
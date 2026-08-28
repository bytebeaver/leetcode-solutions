class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // Set stores all the DISTINCT elements
        // currently present in our sliding window [l ... r].
        //
        // We use it to quickly answer:
        // "Does nums[r] already exist in the current window?"
        unordered_set<int> st;

        // Sum of all elements currently inside
        // the sliding window [l ... r].
        //
        // long long is used because the sum can be larger
        // than the range of int.
        long long current_window_sum = 0;

        // l = left boundary of the window
        // r = right boundary of the window
        int l = 0, r = 0;

        // Stores the maximum sum among all valid
        // windows of size k with distinct elements.
        long long max_sum = 0;

        while (r < n) {

            /*
                STEP 1: HANDLE DUPLICATE

                If nums[r] is already present in the window,
                then adding it would violate the "all elements
                must be distinct" condition.

                Therefore, keep moving l forward until
                nums[r] is no longer present in the window.

                Every time we remove nums[l]:

                1. Remove it from the running sum.
                2. Remove it from the set.
                3. Move l forward.
            */
            while (st.count(nums[r])) {

                // Remove the leftmost element from the window sum
                current_window_sum -= nums[l];

                // Remove that element from the set
                st.erase(nums[l]);

                // Shrink the window from the left
                l++;
            }


            /*
                STEP 2: ADD nums[r]

                At this point nums[r] is NOT present in the
                current window, so adding it keeps all elements
                distinct.
            */
            current_window_sum += nums[r];
            st.insert(nums[r]);


            /*
                STEP 3: CHECK WINDOW SIZE

                Current window is:

                    nums[l ... r]

                Its size is:

                    r - l + 1
            */

            if (r - l + 1 < k) {

                // Window is smaller than k.
                // We need more elements, so simply expand right.
                r++;
            }

            else if (r - l + 1 == k) {

                /*
                    We now have a window of exactly k elements.

                    Since we already handled duplicates above,
                    this window contains k DISTINCT elements.

                    Therefore, it is a valid candidate.
                */

                max_sum = max(max_sum, current_window_sum);


                /*
                    We have processed this window.

                    To create the next window, remove nums[l]
                    and move the left pointer forward.
                */
                current_window_sum -= nums[l];
                st.erase(nums[l]);
                l++;

                // Move right pointer to consider the next element
                r++;
            }
        }

        return max_sum;
    }
};
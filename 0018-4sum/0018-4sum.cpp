class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        // Sorting is important because:
        // 1. It allows the two-pointer technique.
        // 2. It makes duplicate values easy to skip.
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        // -------------------------------------------------
        // STEP 1: Fix the first number using i
        // -------------------------------------------------
        // We need four elements: i, j, l, r.
        // Therefore i can go only up to n-4.
        for(int i = 0; i <= n-4; i++)
        {
            // Skip duplicate values for i.
            // If nums[i] == nums[i-1], starting from this
            // value would create the same set of answers
            // that we already considered for the previous i.
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            // -------------------------------------------------
            // STEP 2: Fix the second number using j
            // -------------------------------------------------
            // j must be after i.
            // We need at least two elements after j for l and r.
            for(int j = i+1; j <= n-3; j++)
            {
                // Skip duplicate values for j.
                // j > i+1 is important because the first possible
                // j for this i must NOT be skipped.
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;

                // -------------------------------------------------
                // STEP 3: Solve the remaining 2Sum using l and r
                // -------------------------------------------------
                int l = j + 1;
                int r = n - 1;

                while(l < r)
                {
                    // Use long long because adding four ints
                    // can overflow int for large values.
                    long long sum =
                        1LL * nums[i] +
                        1LL * nums[j] +
                        1LL * nums[l] +
                        1LL * nums[r];

                    // -------------------------------------------------
                    // CASE 1: We found a valid quadruplet
                    // -------------------------------------------------
                    if(sum == target)
                    {
                        result.push_back({
                            nums[i],
                            nums[j],
                            nums[l],
                            nums[r]
                        });

                        // Move both pointers so we can search
                        // for another possible quadruplet.
                        l++;
                        r--;

                        // Skip repeated values from the left.
                        // Otherwise the same quadruplet may be added again.
                        while(l < r && nums[l] == nums[l-1])
                            l++;

                        // Skip repeated values from the right.
                        while(l < r && nums[r] == nums[r+1])
                            r--;
                    }

                    // -------------------------------------------------
                    // CASE 2: Sum is too large
                    // -------------------------------------------------
                    // Because the array is sorted, decreasing r
                    // decreases the sum.
                    else if(sum > target)
                    {
                        r--;
                    }

                    // -------------------------------------------------
                    // CASE 3: Sum is too small
                    // -------------------------------------------------
                    // Because the array is sorted, increasing l
                    // increases the sum.
                    else
                    {
                        l++;
                    }
                }
            }
        }

        return result;
    }
};
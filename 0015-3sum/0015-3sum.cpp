class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> result;

        // Sorting gives us:
        // 1. Two-pointer monotonic movement.
        // 2. Adjacent duplicates that can be skipped.
        sort(nums.begin(), nums.end());

        // Fix the first element of the triplet.
        for (int i = 0; i <= n - 2; i++) {

            // If the current value is the same as the previous
            // one, processing it again would generate the same
            // triplets. So skip it.
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Two pointers search for the remaining two values.
            int l = i + 1;
            int r = n - 1;

            while (l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                // Sum is too small, so we need a larger value.
                // Because the array is sorted, increasing l
                // increases the sum.
                if (sum < 0) {
                    l++;
                }

                // Sum is too large, so we need a smaller value.
                // Because the array is sorted, decreasing r
                // decreases the sum.
                else if (sum > 0) {
                    r--;
                }

                // Sum is exactly zero: valid triplet found.
                else {

                    // Store the actual VALUES, not the indices.
                    result.push_back({
                        nums[i],
                        nums[l],
                        nums[r]
                    });

                    // Move both pointers away from the current pair.
                    l++;
                    r--;

                    // Skip duplicate left values.
                    // l-1 is valid because l was already incremented.
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    // Skip duplicate right values.
                    // r+1 is valid because r was already decremented.
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }

        return result;
    }
};
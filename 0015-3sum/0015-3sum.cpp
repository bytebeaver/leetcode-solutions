class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;

        // Step 1: Sort the array
        // Time Complexity: O(n log n)
        // Why? Sorting helps us use two-pointer technique efficiently
        // Example: [-1, 0, 1, 2, -1, -4] → [-4, -1, -1, 0, 1, 2]
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element (nums[i])
        // This loop runs 'n' times → O(n)
        for (int i = 0; i < nums.size(); i++)
        {
            // Skip duplicate values for i
            // This ensures we don't repeat the same triplet
            // Example: [-1, -1, 0, 1] → skip second -1
            // Time: O(1) per check
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;              // next element
            int k = nums.size() - 1;   // last element
            
            // Step 3: Two-pointer search
            // For each i, j and k together traverse the array at most once
            // So this loop is O(n) for each i
            while (j < k)
            {   
                int sum = nums[i] + nums[j] + nums[k];

                // Case 1: Found valid triplet
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // Example: [-1, 0, 1]

                    j++;
                    k--;

                    // Skip duplicates for j
                    // Even though it's a while loop, overall j only moves forward
                    // across the array once → amortized O(n) for entire loop
                    while (j < k && nums[j] == nums[j - 1]) j++;

                    // Skip duplicates for k
                    // Same reasoning → amortized O(n)
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }

                // Case 2: Sum too small → increase it
                else if (sum < 0)
                {
                    j++;  // move right → bigger value
                }

                // Case 3: Sum too large → decrease it
                else 
                {
                    k--;  // move left → smaller value
                }
            }
        }

        // Return all unique triplets
        return result;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        // Sort the array so that we can use two pointers.
        sort(nums.begin(), nums.end());

        // Stores the smallest difference from target
        // found so far.
        int mindiff = INT_MAX;

        // Stores the triplet sum corresponding
        // to mindiff.
        int ans;

        // Fix the first element of the triplet.
        for(int i = 0; i <= n - 2; i++)
        {
            // Skip duplicate first elements.
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            // Left pointer starts immediately after i.
            int l = i + 1;

            // Right pointer starts at the last element.
            int r = n - 1;

            // Need two different elements after i.
            while(l < r)
            {
                // Current triplet sum.
                int sum = nums[i] + nums[l] + nums[r];

                // Exact match is the best possible answer.
                if(sum == target)
                {
                    return target;
                }

                // Calculate how far the current sum
                // is from the target.
                int diff = abs(target - sum);

                // If this sum is closer to target than
                // anything found previously, update answer.
                if(diff < mindiff)
                {
                    mindiff = diff;
                    ans = sum;
                }

                // Current sum is smaller than target.
                // We need to increase the sum.
                if(sum < target)
                {
                    l++;

                    // Skip duplicate values.
                    if(l < r && nums[l] == nums[l - 1])
                        l++;
                }

                // Current sum is larger than target.
                // We need to decrease the sum.
                else if(sum > target)
                {
                    r--;

                    // Skip duplicate values.
                    if(l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }

        return ans;
    }
};
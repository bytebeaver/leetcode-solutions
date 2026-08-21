// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
        
//         int n = nums.size();

//         vector<int> prefix_sum(n,0);
//         vector<int> suffix_sum(n,0);

//         for(int i=1; i<n; i++)
//         {
//             prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
//         }

//         suffix_sum[n-1] = 0;
        
//         for(int i=n-2; i>=0; i--)
//         {
//             suffix_sum[i] = suffix_sum[i+1] + nums[i+1];
//         }

//         for(int i = 0; i<n ; i++)
//         {
//             if(prefix_sum[i] == suffix_sum[i])
//             return i;
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();  // array length, needed for both loops

        int sum = 0;

        // Pass 1: calculate total sum of the array once.
        // This total is the baseline from which right sum will be derived later,
        // avoiding the need to loop separately for right sum at each index.
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }

        int left = 0;  // running sum of elements strictly left of current index i

        // Pass 2: single traversal to find the pivot
        for(int i=0; i<n; i++)
        {
            if(i!=0)
            {
            // as we move to next index, the previous element (nums[i-1])
            // now becomes part of the "left side", so add it to running left sum.
            // For i=0, this block is skipped so left correctly stays 0
            // (nothing exists left of index 0).
            left += nums[i-1];
            }
            
            // right sum = total - (everything up to and including current index)
            // this avoids a separate loop to compute right sum explicitly
            int right = sum - (left + nums[i]);

            if(left == right)
            return i;   // first match found = leftmost pivot (since we go left to right)
        }

        return -1;  // no index satisfied the condition
    }
};
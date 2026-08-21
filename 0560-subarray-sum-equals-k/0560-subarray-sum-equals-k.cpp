// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
        
//         int count = 0;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             int sum=0;
//             for(int j=i; j<nums.size(); j++)
//             {
//                 sum += nums[j];

//                 if(sum == k)
//                 count++;

//             }
//         }

//         return count;
//     }
// };


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int prefixSum = 0;       // Sum of elements from the start up to current index
        int subarrayCount = 0;   // Number of subarrays whose sum equals k

        // Stores how many times each prefix sum has occurred.
        // prefixSum -> frequency
        map<int, int> prefixSumFrequency;

        // A prefix sum of 0 exists before we process any element.
        // This handles subarrays that start from index 0.
        prefixSumFrequency[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            // Update the prefix sum by including the current element.
            prefixSum += nums[i];

            // We need an earlier prefix sum such that:
            //
            // current prefixSum - previous prefixSum = k
            //
            // Therefore:
            // previous prefixSum = current prefixSum - k
            int requiredPrefixSum = prefixSum - k;

            // If this prefix sum has occurred before, each occurrence
            // represents one subarray ending at the current index with sum k.
            if (prefixSumFrequency[requiredPrefixSum]) {
                subarrayCount += prefixSumFrequency[requiredPrefixSum];
            }

            // Record the current prefix sum for future subarrays.
            prefixSumFrequency[prefixSum]++;
        }

        return subarrayCount;
    }
};
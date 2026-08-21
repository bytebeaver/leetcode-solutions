class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int arraySize = nums.size();

        // remainderFrequency[r] = number of prefix sums seen so far
        // whose remainder when divided by k is r.
        // We store frequencies because multiple previous prefix sums
        // with the same remainder each create a valid subarray.
        map<int, int> remainderFrequency;

        // Prefix sum before the array starts is 0, so remainder 0
        // has already appeared once. This lets us count subarrays
        // that start from index 0.
        remainderFrequency[0] = 1;

        int prefixSum = 0;
        int subarrayCount = 0;

        for (int index = 0; index < arraySize; index++) {

            // Sum of nums[0...index].
            prefixSum += nums[index];

            // We only care about the prefix-sum remainder.
            // Equal remainders imply a difference divisible by k.
            int remainder = prefixSum % k;

            // C++ can produce negative remainders for negative prefix sums.
            // Normalize into the range [0, k-1].
            if (remainder < 0) {
                remainder += k;
            }

            // Every previous prefix sum with this same remainder
            // creates one valid subarray ending at the current index.
            if (remainderFrequency.find(remainder) != remainderFrequency.end()) {
                subarrayCount += remainderFrequency[remainder];
            }

            // Make the current prefix remainder available for
            // future subarrays.
            remainderFrequency[remainder]++;
        }

        return subarrayCount;
    }
};
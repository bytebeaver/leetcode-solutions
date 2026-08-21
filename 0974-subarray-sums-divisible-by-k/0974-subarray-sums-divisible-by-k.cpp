class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int arraySize = nums.size();

        // remainder -> how many times this remainder has appeared
        map<int, int> remainderFrequency;

        // Before processing any element, prefix sum = 0
        // So remainder 0 has appeared once.
        remainderFrequency[0] = 1;

        int prefixSum = 0;
        int subarrayCount = 0;

        for (int index = 0; index < arraySize; index++) {

            prefixSum += nums[index];

            // C++ can give a negative remainder for a negative prefixSum.
            int remainder = prefixSum % k;

            if (remainder < 0) {
                remainder += k;
            }

            // If this remainder appeared before,
            // each previous occurrence forms a valid subarray.
            if (remainderFrequency.find(remainder) != remainderFrequency.end()) {
                subarrayCount += remainderFrequency[remainder];
            }

            // Record this remainder for future subarrays.
            remainderFrequency[remainder]++;
        }

        return subarrayCount;
    }
};
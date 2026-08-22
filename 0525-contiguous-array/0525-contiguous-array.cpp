class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int countOnes = 0;
        int countZeros = 0;

        // difference -> first index where this difference appeared
        //
        // We store the FIRST occurrence because an earlier index
        // always gives us a longer subarray when the same difference
        // appears again.
        map<int, int> firstOccurrence;

        // Virtual index before the array starts.
        // This allows us to correctly calculate the length when
        // the valid subarray starts from index 0.
        firstOccurrence[0] = -1;

        int maxLength = 0;

        for (int i = 0; i < n; i++) {

            // Maintain the balance between 1s and 0s
            // in the prefix [0 ... i].
            if (nums[i] == 1)
                countOnes++;
            else
                countZeros++;

            // This represents the current balance:
            // positive -> more 1s
            // negative -> more 0s
            // zero     -> equal 0s and 1s
            int difference = countOnes - countZeros;

            // If this same difference appeared earlier,
            // the elements between that earlier index and i
            // must contain equal numbers of 0s and 1s.
            if (firstOccurrence.find(difference) != firstOccurrence.end()) {

                // Use the EARLIEST occurrence of this difference
                // to obtain the longest possible valid subarray.
                maxLength = max(maxLength, i - firstOccurrence[difference]);
            }
            else {
                // Store only the first occurrence.
                // Do not overwrite it later, because an earlier
                // index always produces a longer subarray.
                firstOccurrence[difference] = i;
            }
        }

        return maxLength;
    }
};
class Solution {
public:

    // Calculates the sum of ceil(nums[i] / divisor)
    // for every element in the array.
    int sum_by_divisor(vector<int> arr, int div)
    {
        int sum = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            // We use ceil because the problem says
            // every division result must be rounded UP.
            sum += ceil((double)arr[i] / (double)div);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();

        // Smallest possible positive divisor.
        int low = 1;

        // No need to search beyond the maximum element.
        int high = *max_element(begin(nums), end(nums));

        // Binary search for the FIRST divisor
        // whose sum is <= threshold.
        while(low <= high)
        {
            // Avoids possible overflow compared to (low + high) / 2.
            int mid = low + (high - low) / 2;

            // Treat mid as our candidate divisor.
            int divisor = mid;

            // Calculate the sum produced by this divisor.
            int sum = sum_by_divisor(nums, divisor);

            if(sum <= threshold)
            {
                // mid is a valid divisor.
                // But we need the SMALLEST valid divisor,
                // so search towards the left.
                high = mid - 1;
            }
            else
            {
                // sum > threshold means the divisor is too small.
                // We need a larger divisor.
                low = mid + 1;
            }
        }

        // When the loop ends:
        //
        // high = last invalid divisor
        // low  = first valid divisor
        //
        // Therefore, low is the answer.
        return low;
    }
};
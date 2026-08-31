class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int low = 0;
        int n = arr.size();
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // How many positive integers are missing
            // from 1 to arr[mid]?
            int missing_till_mid = arr[mid] - (mid + 1);

            if(missing_till_mid < k)
            {
                // We haven't found enough missing numbers.
                // Go to the right.
                low = mid + 1;
            }
            else
            {
                // We have found at least k missing numbers.
                // Try to find a smaller position.
                high = mid - 1;
            }
        }

        // high = last position with missing < k
        // low  = first position with missing >= k
        //
        // low = high + 1
        //
        // Answer = high + 1 + k
        return high + 1 + k;
    }
};
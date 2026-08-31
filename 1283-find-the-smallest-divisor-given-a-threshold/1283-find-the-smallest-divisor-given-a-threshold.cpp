class Solution {
public:

    int sum_by_divisor( vector<int> arr, int div)
    {
        int sum = 0;

        for(int i=0; i< arr.size(); i++)
        {
            sum += ceil( (double)arr[i] / (double)div );
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();

        int low = 1;
        int high = *max_element( begin(nums), end(nums));

        while( low<=high)
        {
            int mid = low + (high-low)/2;
            
            int divisor = mid;

            int sum = sum_by_divisor( nums, divisor);

            if( sum <= threshold) //we have a temporary answer ...we can check for smaller divisor
            {
                high = mid-1;
            }

            else if( sum > threshold)
            {
                low = mid+1;
            }
        }

        return low; //cuz finally when loop breaks low will be on first true and high will be on last false
    }
};
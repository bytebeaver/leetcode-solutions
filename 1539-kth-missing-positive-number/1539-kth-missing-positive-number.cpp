class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int low = 0;
        int n = arr.size();
        int high = n-1;

        while( low<=high)
        {
            int mid = low + (high -low)/2;

            int missing_till_mid = arr[mid] - (mid+1);

            if( missing_till_mid < k)
            low = mid+1;

            else 
            high = mid-1;
        }

        return high + 1 + k;
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        // Always binary search on the smaller array -> O(log(min(m,n)))
        // and it also keeps Py = left_half - Px within valid bounds [0, n]
        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = m;

        // total elements needed in the left half (works for both odd/even total length)
        int left_half = (m+n+1)/2;

        while(low <= high)
        {
            // mid = number of elements taken from nums1 into the left half
            int mid = low + (high - low)/2 ;

            int Px = mid;              // elements from nums1 in left half
            int Py = left_half - Px;   // remaining elements from nums2 in left half (auto-derived)

            // x1 = last element of nums1's left part (INT_MIN if nothing taken from nums1)
            int x1 = (Px == 0)? INT_MIN : nums1[Px-1];

            // x2 = last element of nums2's left part (INT_MIN if nothing taken from nums2)
            int x2 = (Py == 0)? INT_MIN : nums2[Py-1];

            // x3 = first element of nums1's right part (INT_MAX if nums1 fully consumed in left half)
            int x3 = (Px == m)? INT_MAX : nums1[Px];

            // x4 = first element of nums2's right part (INT_MAX if nums2 fully consumed in left half)
            int x4 = (Py == n)? INT_MAX : nums2[Py];

            // valid partition check:
            // x1 <= x4 -> nums1-left doesn't exceed nums2-right
            // x2 <= x3 -> nums2-left doesn't exceed nums1-right
            if(x1 <= x4 && x2 <= x3)
            {
                //right partition found

                if( (m+n)%2 == 1) //odd number of elements
                return max(x1, x2); //left half ka last element (max of the two sorted-piece maxes)

                else //even number of elements
                {
                    int t1 = max(x1, x2);   // max of left half
                    int t2 = min(x3, x4);   // min of right half

                    return (t1 + t2)/2.0; //2.0 because it will convert it will give the exact answer as in double
                }

            }

            else if( x1 > x4) //took too many elements from nums1 -> shrink search to the left
                high = mid-1;

            else  // x2 > x3, took too few elements from nums1 -> expand search to the right
                low = mid+1;


        
        }
    return -1;  // unreachable for valid sorted array inputs
    }
};
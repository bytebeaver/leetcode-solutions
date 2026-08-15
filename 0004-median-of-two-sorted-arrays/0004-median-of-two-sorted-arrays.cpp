class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = m;

        int left_half = (m+n+1)/2;

        while(low <= high)
        {
            int mid = low + (high - low)/2 ;

            int Px = mid;

            int Py = left_half - Px;

            int x1 = (Px == 0)? INT_MIN : nums1[Px-1];
            int x2 = (Py == 0)? INT_MIN : nums2[Py-1];


            int x3 = (Px == m)? INT_MAX : nums1[Px];
            int x4 = (Py == n)? INT_MAX : nums2[Py];

            if(x1 <= x4 && x2 <= x3)
            {
                //right partition found
                if( (m+n)%2 == 1) //odd number of elements
                return max(x1, x2); //left half ka last element

                else //even number of elements
                {
                    int t1 = max(x1, x2);
                    int t2 = min(x3, x4);

                    return (t1 + t2)/2.0; //2.0 because it will convert it will give the exact answer as in double
                }

            }

            else if( x1 > x4) //we have to go in left of nums 1
                high = mid-1;

            else 
                low = mid+1;


        
        }
    return -1;
    }
};
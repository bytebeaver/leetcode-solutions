class Solution {
public:

    // Helper: Given a candidate "largest_sum" limit, greedily calculate
    // minimum number of subarrays needed so that no subarray's sum exceeds largest_sum.
    int split(vector<int> &nums , int largest_sum )
    {
        int subarrays = 1;   // at least 1 subarray needed to start with
        int sum = 0;          // running sum of the current (ongoing) subarray

        for(int i=0; i<nums.size(); i++)
        {
            // Check: can current element fit into the ongoing subarray
            // without breaching the largest_sum limit?
            if(sum + (long long)nums[i] <= largest_sum)   // cast to avoid overflow
            {
                sum = sum + nums[i];   // yes, greedily add it to current subarray
            }
            else
            {
                // no, adding this element would exceed the limit
                // so we must start a brand new subarray from this element
                subarrays++;
                sum = nums[i];   // new subarray starts fresh with this element
            }
        }

        return subarrays;   // total subarrays needed for this largest_sum limit
    }


    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        // if we need more subarrays than elements available, impossible
        // (each subarray must be non-empty)
        if(k>n)
        return -1;

        int  l=0, r=0;

        // search space for the answer:
        // l = minimum possible largest_sum = the single biggest element
        //     (this element must live in some subarray, so sum can't be less than it)
        // r = maximum possible largest_sum = sum of entire array
        //     (case when whole array is just 1 subarray)
        for(int i=0; i<n; i++)
        {
            l = max(l,  nums[i]);
            r+=nums[i];
        }


        // Binary search on answer: find the smallest largest_sum
        // for which split() returns <= k subarrays
        while(l<=r)
        {
            int mid = l + (r-l)/2;   // candidate largest_sum

            int subarrays = split(nums, mid);  // how many subarrays needed with this limit?

            if(subarrays <= k)
            {
                // mid is a feasible (maybe overly generous) limit
                // try to find a smaller feasible limit -> search left half
                r= mid-1;
            }

            else if(subarrays > k)
            {
               //matlab jo mid that ---possible candidate for largest_sum : wo km ho gya hai isliye zada subarrays aa rahe hain k se kuki ....hm candidate ko increase kr skte hain kuki hame to k hi subarrays chahie
                l = mid+1;
            }
        }

    // when loop ends, l has crossed over to the first "feasible" value
    // (the smallest largest_sum where split(nums, largest_sum) <= k)
    // this is exactly the minimized largest sum we want
    
    return l;  //becaus the search space follows : F F F F F F F F F T T T T T T .......
    }
};
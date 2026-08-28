class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        

        int n = nums.size();
        unordered_set<int> st;

        long long current_window_sum =0;
       
        int l=0, r=0;
        
        long long max_sum =0;

        while(r<n)
        {
            
            while(st.count( nums[r] ))
            {
                current_window_sum -= nums[l];  
                st.erase( nums[l] );
                l++; 
            }

            current_window_sum += nums[r];
            st.insert( nums[r] );

            if(r-l+1 < k)
            r++;

            else if(r-l+1 == k)
            {
                max_sum = max(max_sum, current_window_sum);
                current_window_sum -= nums[l];
                st.erase( nums[l] );
                l++;
                r++;

            }
        }
          

    return max_sum;
    }
};
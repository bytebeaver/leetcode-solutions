class Solution {
public:


    int subarraysWith_atmost_KDistinct(vector<int>& nums, int k) {
        
        if( k == 0) return 0;

        int n = nums.size();

        int l=0;
        int r=0;

        int count = 0;

        map<int, int> num_freq;

        while( r<n)
        {
            num_freq[ nums[r] ]++;

            while(num_freq.size() > k)
            {
                num_freq[nums[l]]--;

                if(num_freq[ nums[l] ] == 0)
                num_freq.erase( nums[l] );

                l++;
            }

            count += r-l+1;
            r++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();

        int Alpha = subarraysWith_atmost_KDistinct(nums, k);
        int Beta = subarraysWith_atmost_KDistinct(nums, k-1);

        return Alpha-Beta;

    }
};
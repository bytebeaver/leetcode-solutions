class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        

        int n = nums.size();
        map<int, int> mp;

        long long sum =0;
        // mp[ nums[0] ] = 0;
        int l=0, r=0;
        
        long long max_sum =0;

        while(r<n)
        {
            sum += nums[r];

            if(mp.find(nums[r]) != mp.end() && mp[nums[r]] >= l)
            {
                while(l!= mp[nums[r]] + 1)
                {
                    sum-=nums[l];
                    l++;
                }
            }

            if( r-l+1 < k)
            {
                mp[nums[r]] = r;
                r++;
            }

            else if(r-l+1 == k)
            {
                mp[nums[r]] = r;

                max_sum = max(max_sum , sum);
                sum -= nums[l];
                l++;
                r++;
            }

        }

    return max_sum;
    }
};
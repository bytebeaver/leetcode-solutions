class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        set<int> index_of_flipped_zeroes;

        int n = nums.size();

        int l=0, r=0;

        int length = 0;
        int max_len = 0;

        int zeroes =0;

        while(r<n)
        {
            if(nums[r] == 0)
            zeroes++;

            while(zeroes > k)
            {
                if(nums[l] == 0)
                zeroes--;

                l++;
            }

            if(zeroes<=k)
            {
                length = r-l+1;
                max_len = max(max_len, length);
            }

            r++;
        }
        return max_len;
    }
};
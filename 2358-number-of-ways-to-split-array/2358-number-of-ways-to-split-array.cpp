class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();
        
        long long total_sum = 0;

        for(int &num:nums)
        {
            total_sum+=num;
        }

        int split=0;
        long long leftsum=0;
        long long rightsum=0;

        for(int i=0; i<=n-2;i++)
        {
            leftsum+=nums[i];
            rightsum=total_sum - leftsum;

            if(leftsum >= rightsum)
            split++;
        }


        return split;
    }
};
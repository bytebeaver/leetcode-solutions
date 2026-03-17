class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int len = nums.size();

        if(len==1)
        {   
            nums[0]=nums[0]*nums[0];
            return nums;
        }

        int i=0;

        while(i<len && nums[i]<0 )
        i++;

        if(i==0)
        {
            for(int &it:nums)
            {
                it = it*it;
            }
            return nums;
        }

        int j=i-1;

        vector<int>result;

        for(int &it:nums)
            {
                it = it*it;
            }


        while(j>=0 && i<len)
        {
            if(nums[j]<nums[i])
            {
            result.push_back(nums[j]);
            j--;
            }

            else if(nums[i]<=nums[j])
            {
            result.push_back(nums[i]);
            i++;
            }
        }

        if(j<0)
        {
            while(i<len)
            {
            result.push_back(nums[i]);
            i++;
            }
        }

        else if(i>=len)
        {
            while(j>=0)
            {
                result.push_back(nums[j]);
                j--;
            }
        }


        return result;

        
    }
};
class Solution {
public:
    int digit(int nums){
        int sum = 0;
        while(nums>0){
            sum += nums%10;
            nums /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int mpp[82] = {0};//cuz maximum num can be 999999999 => 81
        int res = -1;
        for(int i=0;i<nums.size();i++){
            int sum_of_digits = digit(nums[i]);
            if(mpp[sum_of_digits]>0 /*positive integers in aaray*/)
            {
                int sum = nums[i] + mpp[sum_of_digits];
                res = max(res,sum);
            }
            mpp[sum_of_digits] = max(mpp[sum_of_digits],nums[i]);
            
        }
        return res;
    }
};
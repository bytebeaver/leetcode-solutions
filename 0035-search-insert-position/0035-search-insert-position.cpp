class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
     int n = nums.size();
        
        if(target > nums[n-1])
            return n;
        if(target < nums[0])
            return 0;
        
        int s=0;
        int e=n-1;
        int mid;
        
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(s==e && nums[mid]!=target)
            break; 
            if(nums[mid]==target)
                return mid;
            
            else if(nums[mid]>target)
                e=mid-1;
            
            else if(nums[mid]<target)
                s=mid+1;
        }
        int ans = -1;
        
        if(s==e || s>e)
       {
        if(target<nums[s])
        ans=s;

        else if(target>nums[s])
        ans=s+1;
       }
        return ans;
    }
};
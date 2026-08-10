class Solution {
public:


    int findPartition(vector<int> nums ,int i , int j)
    {
        if(i==j)
        return i;

        int partition;

        int mid = (i+j)/2;
        
          if(i==mid)
        {
            if(nums[i]<nums[i+1])
            return i+1;

            else
            return i;
        }

        if(nums[mid] < nums[i])
        partition = findPartition(nums , i, mid-1);

        else if(nums[mid] > nums[i])
         partition = findPartition(nums , mid, j);

        return partition;
    }

    
    int binarySearch(vector<int> & nums, int i , int j, int target)
    {

        if(i>j)
        return -1;

        int result;

        int mid = (i+j)/2;

        if(target == nums[mid])
        return mid;

      
        if(target < nums[mid])
        result = binarySearch(nums, i, mid-1, target);

        else 
        result = binarySearch(nums, mid+1, j, target);

        return result;

    }

    int search(vector<int>& nums, int target) {
        
        int partition = findPartition(nums , 0 , nums.size()-1);

        if(target == nums[partition] ) return partition;

        if(target >= nums[0]) //search in the prior part
        return binarySearch(nums, 0, partition, target);

        else
        return binarySearch(nums, partition+1, nums.size()-1, target);

    return 0;
    }
};
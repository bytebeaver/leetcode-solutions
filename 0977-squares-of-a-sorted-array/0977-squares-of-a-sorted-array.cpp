class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int len = nums.size();

        // STEP 0: Edge case
        // If only one element, just square it and return
        if(len==1)
        {   
            nums[0]=nums[0]*nums[0];
            return nums;
        }

        int i=0;

        // STEP 1: Find the first non-negative number
        // This splits the array into:
        // left side -> negatives (descending after square)
        // right side -> non-negatives (already sorted after square)
        while(i<len && nums[i]<0 )
            i++;

        // STEP 2: If there are NO negative numbers
        // then array is already sorted → just square everything
        if(i==0)
        {
            for(int &it:nums)
            {
                it = it*it;
            }
            return nums;
        }

        // STEP 3: Setup two pointers
        // j → last negative number
        // i → first non-negative number
        int j=i-1;

        vector<int>result;

        // STEP 4: Square all elements
        // IMPORTANT: Now negatives part becomes decreasing order
        // and positives part remains increasing
        for(int &it:nums)
        {
            it = it*it;
        }

        // STEP 5: Merge the two sorted parts
        // Think of it like merging two sorted arrays:
        // left side (j → 0) is decreasing
        // right side (i → end) is increasing
        while(j>=0 && i<len)
        {
            // Compare smaller square values
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

        // STEP 6: If left side is exhausted
        // just copy remaining right side
        if(j<0)
        {
            while(i<len)
            {
                result.push_back(nums[i]);
                i++;
            }
        }

        // STEP 7: If right side is exhausted
        // copy remaining left side
        else if(i>=len)
        {
            while(j>=0)
            {
                result.push_back(nums[j]);
                j--;
            }
        }

        // STEP 8: Final merged sorted squares array
        return result;
    }
};
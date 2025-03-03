class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int countlessPivot = 0;
        int countequalPivot = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < pivot)
            countlessPivot++;

            if(nums[i] == pivot)
            countequalPivot++;
        }

        int i=0;
        int j=countlessPivot;
        int k=countlessPivot + countequalPivot;

        vector<int>result(nums.size());

        for(int x=0; x<nums.size(); x++)
        {
            if(nums[x] < pivot)
            {
            result[i] = nums[x];
            i++;
            }

            if(nums[x] == pivot)
            {
            result[j] = nums[x];
            j++;
            }

             if(nums[x] > pivot)
            {
            result[k] = nums[x];
            k++;
            }
            
        }

        return result;
    }
};
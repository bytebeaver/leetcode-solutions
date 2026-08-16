class Solution {
public:

   int FindingFirst(vector<int> &nums, int l, int r , int target)
   {
        int first = -1;
        while(l<=r)
        {
            int mid = l+ (r-l)/2;

            if(nums[mid] == target)
            {
                //go left
                first = mid;
                r = mid-1;
            }

            if(nums[mid] > target)
            {
                r = mid-1;
            }

            else if(nums[mid] < target)
            {
                l=mid+1;
            }
        }

        return first;
   }

   int FindingLast(vector<int> &nums, int l, int r , int target)
   {
        int Last = -1;
        while(l<=r)
        {
            int mid = l+ (r-l)/2;

            if(nums[mid] == target)
            {
                //go right
                Last = mid;
                l = mid+1;
            }
            if(nums[mid] < target)
            {
                l=mid+1;
            }

            else if(nums[mid] > target)
            {
                r= mid-1;
            }
        }

        return Last;
   }


    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();


        int l=0;
        int r = n-1;

        int first = FindingFirst(nums, l , r, target);
        int last = FindingLast(nums, l,r, target);

        vector<int> result;

        result.push_back(first);
        result.push_back(last);

        return result;

    }
};
class Solution {
public:

   int FindingFirst(vector<int> &nums, int l, int r , int target)
   {
        int first = -1; // default: target nahi mila

        while(l<=r)
        {
            int mid = l + (r-l)/2; // overflow-safe mid calculation

            if(nums[mid] == target)
            {
                // candidate mila, par leftmost chahiye
                // isliye store karke left half mein aur dhundho
                first = mid;
                r = mid-1; // go left
            }

            else if(nums[mid] > target)
            {
                // target bayi taraf hai
                r = mid-1;
            }

            else if(nums[mid] < target)
            {
                // target dayi taraf hai
                l = mid+1;
            }
        }

        return first;
   }

   int FindingLast(vector<int> &nums, int l, int r , int target)
   {
        int Last = -1; // default: target nahi mila

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] == target)
            {
                // candidate mila, par rightmost chahiye
                // isliye store karke right half mein aur dhundho
                Last = mid;
                l = mid+1; // go right
            }
            else if(nums[mid] < target)
            {
                // target dayi taraf hai
                l = mid+1;
            }

            else if(nums[mid] > target)
            {
                // target bayi taraf hai
                r = mid-1;
            }
        }

        return Last;
   }


    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        int l = 0;
        int r = n-1;

        // dono independent binary searches — koi shared state nahi
        int first = FindingFirst(nums, l, r, target);
        int last = FindingLast(nums, l, r, target);

        vector<int> result;
        result.push_back(first);
        result.push_back(last);

        return result;
    }
};